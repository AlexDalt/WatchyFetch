#include <Watchy.h>
#include "settings.h"
#include "DejaVu_Sans_Mono_Nerd_Font_Complete_Mono9pt7b.h" //include any fonts you want to use
#include "DejaVu_Sans_Mono_Bold_Nerd_Font_Complete_Mono9pt7b.h" //include any fonts you want to use

class Neofetch : public Watchy {
	public:
		Neofetch(const watchySettings& s) : Watchy(s) {}
		void drawWatchFace(){ //override this method to customize how the watch face looks
			if(currentTime.Hour == 00 && currentTime.Minute == 00) {
				sensor.resetStepCounter();
			}
      
			char time[6];
			time[0] = '0' + ((currentTime.Hour/10)%10);
			time[1] = '0' + (currentTime.Hour%10);
			time[2] = ':';
			time[3] = '0' + ((currentTime.Minute/10)%10);
			time[4] = '0' + (currentTime.Minute%10);
			time[5] = 0;

			String date = "";
			date += tmYearToCalendar(currentTime.Year);
			date += "-";
			if (currentTime.Month < 10) date += "0";
			date += currentTime.Month;
			date += "-";
			if (currentTime.Day < 10) date += "0";
			date += currentTime.Day;

			String textstring;
			float VBAT = getBatteryVoltage();
			if(VBAT > 4.2){
				textstring ="100%";
			}
			else if(VBAT > 4.1 && VBAT <= 4.2){
				textstring = "99%";
			}
			else if(VBAT > 4.08 && VBAT <= 4.1){
				textstring = "95%";
			}
			else if(VBAT > 4.06 && VBAT <= 4.08){
				textstring = "90%";
			}
			else if(VBAT > 4.04 && VBAT <= 4.06){
				textstring = "85%";
			}    
			else if(VBAT > 4.02 && VBAT <= 4.04){
				textstring = "80%";
			}    
			else if(VBAT > 4.00 && VBAT <= 4.02){
				textstring = "75%";
			}    
			else if(VBAT > 3.98 && VBAT <= 4.00){
				textstring = "70%";
			}    
			else if(VBAT > 3.96 && VBAT <= 3.98){
				textstring = "65%";
			}
			else if(VBAT > 3.94 && VBAT <= 3.96){
				textstring = "60%";
			}    
			else if(VBAT > 3.92 && VBAT <= 3.94){
				textstring = "55%";
			}    
			else if(VBAT > 3.90 && VBAT <= 3.92){
				textstring = "45%";
			}    
			else if(VBAT > 3.88 && VBAT <= 3.90){
				textstring = "40%";
			}    
			else if(VBAT > 3.86 && VBAT <= 3.88){
				textstring = "35%";
			}
			else if(VBAT > 3.84 && VBAT <= 3.86){
				textstring = "30%";
			}    
			else if(VBAT > 3.82 && VBAT <= 3.84){
				textstring = "25%";
			}    
			else if(VBAT > 3.80 && VBAT <= 3.82){
				textstring = "20%";
			}    
			else if(VBAT > 3.78 && VBAT <= 3.80){
				textstring = "15%";
			}    
			else if(VBAT > 3.76 && VBAT <= 3.78){
				textstring = "10%";
			}
			else if(VBAT > 3.74 && VBAT <= 3.76){
				textstring = "5%";
			}    
			else if(VBAT <= 3.73){
				textstring = "1%";
			}
			
			display.fillScreen(GxEPD_BLACK);
			display.setTextColor(GxEPD_WHITE);
			display.setFont(&DejaVu_Sans_Mono_Nerd_Font_Complete_Mono9pt7b);
			display.setCursor(0, 21);

			String wifi = WIFI_CONFIGURED ? "CON" : "DIS";

			display.println(" $ fetch");
			display.print(" alex")
			display.setFont(&DejaVu_Sans_Mono_Bold_Nerd_Font_Complete_Mono9pt7b);
			display.print("@")
			display.setFont(&DejaVu_Sans_Mono_Nerd_Font_Complete_Mono9pt7b);
			display.println("watchy")
			display.println(" ----------------");
			display.setFont(&DejaVu_Sans_Mono_Bold_Nerd_Font_Complete_Mono9pt7b);
			display.print(" Time: ");
			display.setFont(&DejaVu_Sans_Mono_Nerd_Font_Complete_Mono9pt7b);
			display.println(time);
			display.setFont(&DejaVu_Sans_Mono_Bold_Nerd_Font_Complete_Mono9pt7b);
			display.print(" Date: ");
			display.setFont(&DejaVu_Sans_Mono_Nerd_Font_Complete_Mono9pt7b);
			display.println(date);
			display.setFont(&DejaVu_Sans_Mono_Bold_Nerd_Font_Complete_Mono9pt7b);
			display.print(" Wifi: ");
			display.setFont(&DejaVu_Sans_Mono_Nerd_Font_Complete_Mono9pt7b);
			display.println(wifi);
			display.setFont(&DejaVu_Sans_Mono_Bold_Nerd_Font_Complete_Mono9pt7b);
			display.print(" Battery: ");
			display.setFont(&DejaVu_Sans_Mono_Nerd_Font_Complete_Mono9pt7b);
			display.println(textstring);
			display.setFont(&DejaVu_Sans_Mono_Bold_Nerd_Font_Complete_Mono9pt7b);
			display.print(" Steps: ");
			display.setFont(&DejaVu_Sans_Mono_Nerd_Font_Complete_Mono9pt7b);
			display.println(sensor.getCounter());
			display.println(" $ _");
		}
};

Neofetch m(settings);

void setup(){
  m.init();
}

void loop(){}
