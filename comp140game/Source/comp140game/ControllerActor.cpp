// Fill out your copyright notice in the Description page of Project Settings.
//https://answers.unrealengine.com/questions/101092/how-does-parseintoarray-work-in-c.html

#include "comp140game.h"
#include "ControllerActor.h"


// Sets default values
AControllerActor::AControllerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// connect to port using wide character string 'L'
	this->connect(L"COM5");

	// check connection
	if (this->IsConnected()) UE_LOG(LogTemp, Warning, TEXT("Connection Success"));
	str = FString("");
}
void AControllerActor::connect(wchar_t *portName) {


	//We're not yet connected
	this->connected = false;

	//Try to connect to the given port throuh CreateFile
	this->hSerial = CreateFile(portName,
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	//Check if the connection was successfull
	if (this->hSerial == INVALID_HANDLE_VALUE) {
		//If not success full display an Error
		if (GetLastError() == ERROR_FILE_NOT_FOUND) {

			UE_LOG(LogTemp, Warning, TEXT("Connection Failure - port not available"));

		}
		else {

			UE_LOG(LogTemp, Warning, TEXT("Connection Failure - reason unknown"));
		}
	}
	else {

		//If connected we try to set the comm parameters
		DCB dcbSerialParams = { 0 };

		//Try to get the current
		if (!GetCommState(this->hSerial, &dcbSerialParams)) {
			//If impossible, show an error
			UE_LOG(LogTemp, Warning, TEXT("failed to get current serial parameters!"));
		}
		else {
			//Define serial connection parameters for the arduino board
			dcbSerialParams.BaudRate = CBR_115200;
			dcbSerialParams.ByteSize = 8;
			dcbSerialParams.StopBits = ONESTOPBIT;
			dcbSerialParams.Parity = NOPARITY;

			//Setting the DTR to Control_Enable ensures that the Arduino is properly
			//reset upon establishing a connection
			dcbSerialParams.fDtrControl = DTR_CONTROL_ENABLE;

			//Set the parameters and check for their proper application
			if (!SetCommState(hSerial, &dcbSerialParams)) {
				UE_LOG(LogTemp, Warning, TEXT("ALERT: Could not set Serial Port parameters"));
			}
			else {
				//If everything went fine we're connected
				this->connected = true;
				//Flush any remaining characters in the buffers 
				PurgeComm(this->hSerial, PURGE_RXCLEAR | PURGE_TXCLEAR);
				//We wait 2s as the arduino board will be reseting
				Sleep(ARDUINO_WAIT_TIME);
			}
		}
	}
}

unsigned long int AControllerActor::ReadData(char *buffer, unsigned int nbChar)
{
	//Number of bytes we'll have read
	unsigned long int bytesRead;

	//Number of bytes we'll really ask to read
	unsigned int toRead;

	//Use the ClearCommError function to get status info on the Serial port
	ClearCommError(this->hSerial, this->errors, &this->status);

	//Check if there is something to read
	if (this->status.cbInQue>0)
	{
		//If there is we check if there is enough data to read the required number
		//of characters, if not we'll read only the available characters to prevent
		//locking of the application.
		if (this->status.cbInQue>nbChar)
		{
			toRead = nbChar;
		}
		else
		{
			toRead = this->status.cbInQue;
		}

		//UE_LOG(LogTemp, Warning, TEXT("bytes to %d"), toRead);
		//Try to read the require number of chars, and return the number of read bytes on success
		if (ReadFile(this->hSerial, buffer, toRead, &bytesRead, NULL))
		{
			//UE_LOG(LogTemp, Warning, TEXT("bytes read %d"), bytesRead);
			return bytesRead;
		}

	}

	//If nothing has been read, or that an error was detected return 0
	return 0;

}

// Called when the game starts or when spawned
void AControllerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AControllerActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	char incomingData[256] = "";			// don't forget to pre-allocate memory
											//printf("%s\n",incomingData);
	int dataLength = 255;
	int readResult = 0;

	// Check if we are connected before we try to read from the port
	if (this->IsConnected()) {

		// check if there is data
		readResult = this->ReadData(incomingData, dataLength); 
		str= FString(ANSI_TO_TCHAR(incomingData));
		if (str.Len() > 17)
		{
			StickInput.Empty();
			//parse the string 
			str.ParseIntoArray(StickInput, TEXT(":"), true);
			for (FString& Input:StickInput)
			{
			UE_LOG(LogTemp, Warning, TEXT("%s\n"), *Input);
			}
		}
		else
		{
			StickInput.Empty();
		
		}
		//int32 firstindex = 0;
		//int32 lastindex = 0;
		//if (str.FindChar('C',firstindex) && (str.FindLastChar('C',lastindex))) 
		//{
			//FString ControllerString = str.RightChop(firstindex);
			//ControllerString=ControllerString.LeftChop(lastindex);
			//UE_LOG(LogTemp, Warning, TEXT("%s\n"), *str);
			//str = FString("");
			
		//}

		// convert string so it is compatible with Unreal
		//str.Append(FString(ANSI_TO_TCHAR(incomingData)));
		//str.TrimToNullTerminator();

		//parse the string 
		 //str.ParseIntoArray(StickInput, TEXT(":"), true);
		 //for (FString& Input:StickInput)
		//{
			//UE_LOG(LogTemp, Warning, TEXT("%s\n"), *Input);
		//}

		// output data to console
		//UE_LOG(LogTemp, Warning, TEXT("%s\n"), *str);

		// clear the data ready for the next tick
		incomingData[readResult] = 0;

	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Not Connected"));
	}


}

bool AControllerActor::IsConnected()
{
	//Simply return the connection status
	return this->connected;
}

void AControllerActor::EndPlay(const EEndPlayReason::Type EndPlayReason) {

	Super::EndPlay(EndPlayReason);

	//Check if we are connected before trying to disconnect
	if (this->connected)
	{
		//We're no longer connected
		this->connected = false;
		//Close the serial handler
		CloseHandle(this->hSerial);
	}
}