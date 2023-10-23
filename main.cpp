#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>

class IInstrument
{
public:
	
	virtual void Play()=0;
};

class Guiter : public IInstrument
{
public:
	void Play() override {
		printf("ギターを演奏した。\n");
	};
};

class Drums : public IInstrument
{
public:
	void Play() {
		printf("ドラムを演奏した。\n");
	};
};

int main() {
	IInstrument* instruments[2];
	instruments[0] = new Guiter;
	instruments[1] = new Drums;

	for (IInstrument* instrument : instruments) {
		instrument->Play();
	}
	
	for (IInstrument* instrument : instruments) {
		delete instrument;
	}

	return 0;
}