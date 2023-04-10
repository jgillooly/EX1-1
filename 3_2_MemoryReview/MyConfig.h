#pragma once
struct _BuffByte {
	char myByte;
};
struct _Wifi {
	char SSID[51];
	_BuffByte BuffW1;
	char Pswd[51];
	_BuffByte BuffW2;
};

struct _Version {
	short major;
	short minor;
	short revision;
};

struct Config {
	_Version Version;
	_Wifi wifi;
	_BuffByte Buffl;
};