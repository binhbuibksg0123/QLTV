#include <math.h>

//==
bool  CheckLetter(char s);
bool  CheckNum(char s);
bool  KhoaNhapLieu(char s[], int n);
char* toChars(unsigned long long num);
char* charDate(int day, int month, int year);
int   KiemtraNhapLieu(char c, char s[]);
int   canLeGiua(char *S, int dis);
void  AddChuoi(char c, char s[]);
void  get_chuoi(char *des, char *s );
void  delBlank(char *s);
void  Nhap(int x, int y, int check, char c, char s[], int n);
unsigned long long  ChangeCharToNum (char s[]);
//

bool CheckLetter(char s){ // kiem tra la chu
	if((s>= 65 && s<= 90) || (s>= 97 && s<= 122 ) || (s==32)){
		return 1;
	}
	return 0;	 
}

bool CheckNum(char s){ // kiem tra la so
		if(s >= 48 && s <= 57){
			return 1;
		}
	return 0;	 
}

unsigned long long ChangeCharToNum (char s[]){ // chuyen ky tu sang so
	unsigned long long n = 0;
	for(int i = 0; i<strlen(s);i++){
		n *= 10;
		n += (s[i]-48);
	}
	return n;
}

char* toChars(unsigned long long num){
	char* a = new char[100];
	if (num == 0){
		a[1] = '\0';
		a[0] = '0';
	}
	else{
		int l = floor(log10(num)+1);
		a[l--] = '\0';
		while(num>0){
			a[l--] = num%10+48; //to char
			num/=10;
		}
	}
	return a;
}
void AddChuoi(char c, char s[]){
	strncat(s, &c,1);
}

void get_chuoi(char *des, char *s ){
	int it = 0;
	for(int i=0; i<strlen(s); i++){
		if(s[i] != ' '){
			des[it] = toupper(s[i]); // chuyen thanh chu in hoa
			it++;
		}
	}
	des[it] ='\0';
}

void delBlank(char *s){
	for(int i = 0; i < strlen(s); i++){
		if(s[i]==' '){
			s[i] = s[i+1];
			for(int j = i+1;j<strlen(s)-1;j++){
				s[j] = s[j+1];
			}
			s[strlen(s)-1] = '\0';
		}
	}
}

int KiemtraNhapLieu(char c, char s[]){
	if(strlen(s) == 0 && c == ' ') // khoa khoang trong
		return 0;
	else	
		if(strlen(s) != 0 && s[strlen(s)-1] == ' ' && c == ' ') // khoa 2 khoang trong 
			return 0;	
	else	
		if((strlen(s) != 0 && s[strlen(s)-1] == ' ' && c != ' ') || (strlen(s) == 0 && c != ' '))// viet hoa ki tu sau dau cach
			return -1;
	return 1;	 
}

bool KhoaNhapLieu(char s[], int n){
	if(strlen(s)<n)
		return 1;
	return 0;	
}

void Nhap(int x, int y,int check, char c, char s[], int n){
//	c = tolower(c);
	if(c == 8 && strlen(s) != 0){ //8: Backspace
		s[strlen(s)-1] = '\0';
	}	
	if(check == 1){
		if(CheckLetter(c) && KhoaNhapLieu(s,n))
		{
			if(KiemtraNhapLieu(c,s) == 1){
				AddChuoi(c,s);
			//	outtextxy(x,y,s);
			}
			else
				if(KiemtraNhapLieu(c,s)==-1){
					c = toupper(c);
					AddChuoi(c,s);
				}		
		}
		
	}
	else if(check==0){
		if(CheckNum(c) && KhoaNhapLieu(s,n)){
			if(KiemtraNhapLieu(c,s) == 1 || KiemtraNhapLieu(c,s) == -1){
				AddChuoi(c,s);
			}
		}
	}
	else if(check == -1){
		if((CheckNum(c) || CheckLetter(c)) && KhoaNhapLieu(s,n) ){
			
			if(KiemtraNhapLieu(c,s) == 1|| KiemtraNhapLieu(c,s) == -1){
				c = toupper(c);
				AddChuoi(c,s);
			}
		}
	}
	else if(check == 2){
		if((CheckNum(c) || CheckLetter(c)) && KhoaNhapLieu(s,n)){
			
			if(KiemtraNhapLieu(c,s) == 1){
				AddChuoi(c,s);
//				outtextxy(x,y,s);
			}
			else
				if(KiemtraNhapLieu(c,s)==-1){
					c = toupper(c);
					AddChuoi(c,s);
				}
		}
	} 
	setcolor(WHITE);
	setbkcolor(NEN_TEXT);
	outtextxy(x,y,s);
}

int toInt(char content[]){
	int x = 0;
	for(int i=0; i<strlen(content); i++){
		if(i > 0 && content[i] == '_') break;
		if(content[i] >= '0' && content[i] <= '9') x = x*10 + (content[i]-'0');
		else return -1;
	}
	return x;
}

int canLeGiua(char *S, int dis){
	return (dis-textwidth(S))/2;
}


/*//Ham do hoa

void InThongTin(int x, int y, const char *s)
{
	setcolor(WHITE);
	setbkcolor(NEN_TEXT);
	outtextxy(x, y, s);
}

void ThongBao(int x, int y, char noti[50], int mauChu, int mauNen)
{	
	setbkcolor(mauNen);
	setcolor(mauChu);
	outtextxy(x, y, noti);
	Sleep(DELAY_NOTI);
	setfillstyle(SOLID_FILL, mauNen);
	bar(x, y, x + textwidth(noti), y + textheight(noti));
}

void showPage(int x, int y, int page, int limit)
{
	//  Page: page / limit
	setcolor(MAU_TEXT_KHUNG);
	setbkcolor(MAU_NEN);
	outtextxy(x, y, "Page: ");
	x += textwidth("Page: ");
	
	outtextxy(x, y, toChars(page));
	x += textwidth(toChars(page));
	
	outtextxy(x, y, " / ");
	x += textwidth(" / ");	
	
	outtextxy(x, y, toChars(limit));
}

char* charDate(int day, int month, int year)
{
	char *res = new char[100];
	res[0] = '\0';
	
	if (day < 10)
		strcat(res, "0");
	strcat(res, toChars(day));
	strcat(res, "/");
	
	if (month < 10)
		strcat(res, "0");
	strcat(res, toChars(month));
	strcat(res, "/");
	
	if (year < 10)
		strcat(res, "0");
	if (year < 100)
		strcat(res, "0");
	if (year < 1000)
		strcat(res, "0");
	strcat(res, toChars(year));
	
	return res;
}*/

