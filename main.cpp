#include <stdio.h>
#include <algorithm>
#include <list>
int main() {
	std::list<const char*>yamanoteLine{"Tokyo","Kanda","Akihanara","Okatimati","Ueno","Uguisudani",
		"Nippori","Tabata","Komairi","Sugamo","Otsuka","Ikebukuro","Mejiro","Takadanobaba","Shin-Okubo",
		"Shinjuku","Yoyogi","Harajuku","Shibuya","Ebisu","Meguro","Gotanda","Osaki","Shinagawa","Tamachi","Hamamatsucho",
	"Shimbashi","Yurakucho"};
	std::list<const char*>::iterator yamanoteLineIterator = yamanoteLine.begin();
	int num = 0;
	printf("1970\n");
	for (std::list<const char*>::iterator iterator = yamanoteLine.begin(); iterator != yamanoteLine.end(); iterator++) {
		printf("%02d,%s\n",++num,*iterator);
	}
	yamanoteLineIterator = std::find(yamanoteLine.begin(), yamanoteLine.end(),"Tabata");
	if (yamanoteLineIterator != yamanoteLine.end()) {
		yamanoteLine.insert(yamanoteLineIterator,"Nishi-Nippori");
	}
	printf("\n2019\n");
	num = 0;
	for (std::list<const char*>::iterator iterator = yamanoteLine.begin(); iterator != yamanoteLine.end(); iterator++) {
		printf("%02d,%s\n", ++num, *iterator);
	}
	yamanoteLineIterator = std::find(yamanoteLine.begin(), yamanoteLine.end(), "Tamachi");
	if (yamanoteLineIterator != yamanoteLine.end()) {
		yamanoteLine.insert(yamanoteLineIterator, "Takanawa GateWay");
	}
	printf("\n2022\n");
	num = 0;
	for (std::list<const char*>::iterator iterator = yamanoteLine.begin(); iterator != yamanoteLine.end(); iterator++) {
		printf("%02d,%s\n", ++num, *iterator);
	}
	return 0;
}