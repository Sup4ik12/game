#include "TXLib.h"

struct cat
{
    HDC R;
    HDC L;
    HDC U;
    HDC D;
    HDC RD;
    HDC LD;
    HDC RU;
    HDC LU;
    HDC image;
    int w;
    int h;
    int x;
    int y;
    int v;
    int v1;
    int nKad;
    void drawCat()
    {
        txTransparentBlt(txDC(),x,y,w,h,image,w*nKad,0,RGB(150,150,100));
        if (image == R|| image == L )
        {
            txTransparentBlt (txDC(), x, y, w, h, image, w*nKad, 0, RGB(150,150,100));
        }
        else if (image == U || image == D )
        {
            txTransparentBlt (txDC(), x, y, h, w, image, w*nKad, 0, RGB(150,150,100));
        }
        if(GetAsyncKeyState ('W') and !GetAsyncKeyState ('D') and !GetAsyncKeyState ('A'))
        {
                image=U;
                y -= v;
                nKad += 1;
                if (nKad>=3) nKad=0;
        }
        if(GetAsyncKeyState ('S') and !GetAsyncKeyState ('D') and !GetAsyncKeyState ('A'))
        {
                image = D;
                y += v;
                nKad += 1;
                if (nKad>=3) nKad=0;
        }
        if(GetAsyncKeyState ('A') and !GetAsyncKeyState ('S') and !GetAsyncKeyState ('W'))
        {
                image = L;
                x -= v;
                nKad += 1;
                if (nKad>=3) nKad=0;

        }
        if(GetAsyncKeyState ('D') and !GetAsyncKeyState ('S') and !GetAsyncKeyState ('W'))
        {
                image = R;
                x += v;
                nKad += 1;
                if (nKad>=3) nKad=0;
        }
        if(GetAsyncKeyState ('D') and GetAsyncKeyState ('S'))
        {
                image = RD;
                x += v;
                y += v;
                nKad += 1;
                if (nKad>=3) nKad=0;
        }
        if(GetAsyncKeyState ('D') and GetAsyncKeyState ('W'))
        {
                image = RU ;
                x += v;
                y -= v;
                nKad += 1;
                if (nKad>=3) nKad=0;
        }
        if(GetAsyncKeyState ('A') and GetAsyncKeyState ('S'))
        {
                image = LD ;
                x -= v;
                y += v;
                nKad += 1;
                if (nKad>=3) nKad=0;
        }
        if(GetAsyncKeyState ('A') and GetAsyncKeyState ('W'))
        {
                image = LU ;
                x -= v;
                y -= v;
                nKad += 1;
                if (nKad>=3) nKad=0;
        }
        if(!GetAsyncKeyState ('S') and !GetAsyncKeyState ('A') and !GetAsyncKeyState ('W') and !GetAsyncKeyState ('D'))
        {
                nKad = 0;
        }
        if(x <= 0)
        {
            x += v;
        }
        if(x+w >= 1920)
        {
            x -= v;
        }
        if(y <= 0)
        {
            y += v;
        }
        if(y+h >= 1080)
        {
            y -= v;
        }

    }
};
struct button
{
  int x;
  int y;
  int w;
  int h;
  const char* text;
  int colorVny;
  int colorVne;
  int r;

  void draw()
    {
     txSetColor(colorVne);
     txSetFillColor(colorVny);
     txSelectFont ("Comic Sans MS", r);
     txRectangle(x,y,x+w,y+h);
     txDrawText(x, y, x+w, y+h, text);
    }
};
struct Icon
{
    int x;
    int y;
    int w;
    int h;
    HDC image;
    bool draw;
    void paint()
    {
        if(draw)
        {
            txTransparentBlt(txDC(),x,y,w,h,image,0,0,RGB(50,201,72));
        }
        else
        {
            txTransparentBlt(txDC(),x,y,w,h,image,200,0,RGB(50,201,72));
        }
    }
};
struct dialog
{
    int x;
    int y;
    int w;
    int h;
    HDC image;
    const char* text;
    int r;
    COLORREF colorVny;
    COLORREF colorVne;
    bool v;

    void draw()
    {
        if(v == true)
        {
            txSetColor(colorVne);
            txSetFillColor(colorVny);
            txBitBlt(txDC(),x,y,w,h,image);
            txSelectFont ("Comic Sans MS", r);
            txDrawText(x+20,y+25,x+w-25,y+h-100,text);
        }
    }
};
struct gran
{
    int x;
    int y;
    int w;
    int h;
    int n;
    HDC image;
    bool v;
    void draw()
    {
        if(v = true)
        {
            txTransparentBlt(txDC(),x,y, w,h,image, w*n, 0,RGB(150,150,150));
        }
    }
};
struct hpBar
{
    int x;
    int y;
    HDC image;
    int w;
    int h;
    int hp;
    void draw()
    {
        char str[50];
        sprintf(str,"%d",hp);
        txTransparentBlt(txDC(),x,y, w,h,image, 0, 0,TX_WHITE);
        txSetColor(RGB(201,16,16));
        txSetFillColor(RGB(234,19,19));
        txRectangle(x+92,y+17,x+92+hp*2.6,y+83);
        txSetColor(RGB(26,2,7));
        txSetFillColor(RGB(26,2,7));
        txSelectFont ("Bahnschrift", 45);
        txDrawText(x+25,y+27,x+83,y+66,str);
    }
};
struct Prizrak
{
    int x;
    int y;
    int w;
    int h;
    HDC L;
    HDC R;
    HDC image;
    int n;
    int x1;
    int y1;
    int t;
    int v;
    void draw(int x1, int y1)
    {
        int vx = (abs(x1-x))/t;
        int vy = (abs(y1-y))/t;
        txTransparentBlt(txDC(),x,y, w,h,image, w*n, 0,RGB(34,177,76));
        if(x1 > x and y1 > y)
        {
            image = R;
            x += vx;
            y += vy;
            n += 1;
            if (n>=4) n=0;
        }
        if(x1 > x and y1 < y)
        {
            image = R;
            x += vx;
            y -= vy;
            n += 1;
            if (n>=4) n=0;
        }
        if(x1 < x and y1 > y)
        {
            image = L;
            x -= vx;
            y += vy;
            n += 1;
            if (n>=4) n=0;
        }
        if(x1 < x and y1 < y)
        {
            image = L;
            x -= vx;
            y -= vy;
            n += 1;
            if (n>=4) n=0;
        }
        if(abs(x1-x)<= 400)
        {
            vx = v;
        }
        if(abs(y1-y) <= 400)
        {
            vy = v;
        }


    }
};
struct plant
{
    int x;
    int y;
    int w;
    int h;
    HDC image;
    int x1;
    int y1;
    int w1;
    int h1;
    int n;
    bool v;

    void draw(int x1,int y1)
    {
        if(((x1+30<x+w) and
            (x1+w1-30>x) and
            (y1+30<y+h) and
            (y1+h1-30>y) and
            (txMouseButtons() == 1)) and v == true)
        {
            n += 1;
            txTransparentBlt(txDC(),x-10000,y, w,h,image, 0, 0,RGB(0,0,255));
            v = false;
        }
        if(v == true)
        {
            txTransparentBlt(txDC(),x,y, w,h,image, 0, 0,RGB(0,0,255));
        }
    }
};
struct square
{
    int x;
    int y;
    int w;
    int h;
    const char* text;
    bool v;
    void draw()
    {
        if(v == true)
        {
            txSetColor(RGB(43,172,156),5);
            txSetFillColor(RGB(56,211,204));
            txRectangle(x,y,x+w,y+h);
            txDrawText(x,y,x+w,y+h,text);
        }
        if(v == false)
        {
            txSetColor(RGB(43,172,156),5);
            txSetFillColor(RGB(56,211,204));
            txRectangle(x-5200,y,x+w,y+h);
            txDrawText(x-5200,y,x+w,y+h,text);
        }

    }
};
int main()
{
    txCreateWindow (1920, 1080);
    txSetColor (TX_WHITE, 5);

    string page = "menu";

    //�������
    HDC location=txLoadImage("����/����.bmp");
    HDC house=txLoadImage("����/���.bmp");
    HDC kushat=txLoadImage("����/�����.bmp");
    HDC kv1=txLoadImage("����/�����1.bmp");
    HDC end1 = txLoadImage("����/�����1.bmp");

    //���������
    cat cat = {txLoadImage("cat/catR.bmp"),txLoadImage("cat/catL.bmp"),txLoadImage("cat/catU.bmp"),txLoadImage("cat/catD.bmp"),txLoadImage("cat/catRD.bmp"),txLoadImage("cat/catLD.bmp"),txLoadImage("cat/catRU.bmp"),txLoadImage("cat/catLU.bmp"),cat.R,83.3,83.3,800,425,15,cat.v/1.5,0};
    HDC cat2 = txLoadImage("cat/�����.bmp");
    HDC sleep = txLoadImage("cat/sleep.bmp");
    gran G = {150,450,350,350,0,txLoadImage("������.bmp")};
    Prizrak ghost = {250,250,107.75,120,txLoadImage("ghost/ghostL.bmp"),txLoadImage("ghost/ghostR.bmp"),ghost.R,0,cat.x,cat.y,9,1};
    Prizrak ghost1 = {1500,250,107.75,120,txLoadImage("ghost/ghostL.bmp"),txLoadImage("ghost/ghostR.bmp"),ghost.R,0,cat.x,cat.y,10,2};
    Prizrak ghost2 = {750,800,107.75,120,txLoadImage("ghost/ghostL.bmp"),txLoadImage("ghost/ghostR.bmp"),ghost.R,0,cat.x,cat.y,6,2.5};

    //��������
    HDC Lose=txLoadImage("��������/�����������.bmp");
    HDC Victory=txLoadImage("��������/���������.bmp");
    HDC Alone=txLoadImage("��������/�����������.bmp");

    //������
    HDC plate=txLoadImage("���������.bmp");
    Icon c1 = {590,450,200,200,txLoadImage("������/���������.bmp"),true};
    Icon c2 = {590,450,200,175,txLoadImage("������/�����������.bmp"),true};
    dialog DI = {1,1,720,469,txLoadImage("������.bmp"),"d",50,RGB(150, 108, 33),RGB(133, 98, 37)};
    hpBar helf = {210,850,txLoadImage("hpBar.bmp"),373,100,30};
    button btnSt = {500,250,150,75,"�����",TX_WHITE,TX_RED,30};
    button btnHe = {750,500,150,75,"������",TX_WHITE,TX_RED,30};
    button btnEx = {1000,750,150,75,"����",TX_WHITE,TX_RED,30};
    button btnV1 = {850,700,200,75,"���",RGB(227, 185, 109),RGB(133, 98, 37),100};
    button btnV2 = {600,700,200,75,"*��������*",RGB(227, 185, 109),RGB(133, 98, 37),38};
    square sq  = {30,900,270,130,"����� �����",true};

    //��������
    plant astr1 = {407,66,130,246,txLoadImage("������/�����.bmp"),cat.x,cat.y,cat.w,cat.h,0,true};
    plant astr2 = {1040,670-246,130,246,astr1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant astr3 = {1401,300-246,130,246,astr1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant astr4 = {1690,854-246,130,246,astr1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant astr5 = {1258,847-246,130,246,astr1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant astr6 = {530,852-246,130,246,astr1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant astr7 = {140,672-246,130,246,astr1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant astr8 = {795,314-246,130,246,astr1.image,cat.x,cat.y,cat.w,cat.h,0,true};

    plant aloe1 = {601,305-147,130,147,txLoadImage("������/����.bmp"),cat.x,cat.y,cat.w,cat.h,0,true};
    plant aloe2 = {324,662-147,130,147,aloe1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant aloe3 = {1619,487-147,130,147,aloe1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant aloe4 = {1203,300-147,130,147,aloe1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant aloe5 = {191,482-147,130,147,aloe1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant aloe6 = {765,669-147,130,147,aloe1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant aloe7 = {1040,862-147,130,147,aloe1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant aloe8 = {1455,661-147,130,147,aloe1.image,cat.x,cat.y,cat.w,cat.h,0,true};

    plant cact1 = {200,306-177,130,177,txLoadImage("������/������.bmp"),cat.x,cat.y,cat.w,cat.h,0,true};
    plant cact2 = {310,840-177,130,177,cact1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant cact3 = {780,488-177,130,177,cact1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant cact4 = {553,650-177,130,177,cact1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant cact5 = {1014,301-177,130,177,cact1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant cact6 = {1240,650-177,130,177,cact1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant cact7 = {1426,480-177,130,177,cact1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant cact8 = {1597,306-177,130,177,cact1.image,cat.x,cat.y,cat.w,cat.h,0,true};

    plant sun1 = {110,854-254,130,254,txLoadImage("������/���������.bmp"),cat.x,cat.y,cat.w,cat.h,0,true};
    plant sun2 = {384,485-254,130,254,sun1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant sun3 = {583,482-254,130,254,sun1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant sun4 = {750,850-254,130,254,sun1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant sun5 = {1030,500-254,130,254,sun1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant sun6 = {1233,500-254,130,254,sun1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant sun7 = {1488,850-254,130,254,sun1.image,cat.x,cat.y,cat.w,cat.h,0,true};
    plant sun8 = {1672,672-254,130,254,sun1.image,cat.x,cat.y,cat.w,cat.h,0,true};

    int xL = 0; int yL = 0;
    int nKad = 0;
    int nK = 0;
    int da = 0;
    bool popil = false;
    bool sten = false;
    int kadr = 0;
    int time = 600;
    bool kvest = false;
    bool fight = false;
    bool vibor = false;
    bool task = false;
    bool task1 = true;
    bool task2 = false;
    bool task3 = false;
    bool task4 = false;
    bool done = false;

    int nA = 0;
    int nAl = 0;
    int nC = 0;
    int nP = 0;

    int point = 0;

    char str[50];

    while (page != "exit")
    {
        txSetFillColor(TX_BLACK);
        txClear();
        txBegin();
        txSetFillColor (TX_WHITE);

        if(helf.hp == 0)
        {
            txSleep(2000);
            page = "lose";
        }
         //����
        if(page == "menu")
        {
            btnSt.draw();
            btnHe.draw();
            btnEx.x = 1000; btnEx.y = 750; btnEx.text = "����";
            btnEx.draw();
            if( txMouseButtons() == 1 and
                btnSt.x < txMouseX() and txMouseX() < btnSt.w + btnSt.x and
                btnSt.y < txMouseY() and txMouseY() < btnSt.y + btnSt.h)
            {
                page = "street";
            }
            if( txMouseButtons() == 1 and
                btnHe.x < txMouseX() and txMouseX() < btnHe.w + btnHe.x and
                btnHe.y < txMouseY() and txMouseY() < btnHe.y + btnHe.h)
            {
                page = "help";
            }
            if( txMouseButtons() == 1 and
                btnEx.x < txMouseX() and txMouseX() < btnEx.w + btnEx.x and
                btnEx.y < txMouseY() and txMouseY() < btnEx.y + btnEx.h)
            {
                page = "exit";
            }
        }

        if(page == "help")
        {
            btnEx.x = 1750; btnEx.y = 900; btnEx.text = "�����"; btnEx.draw();
            txSetColor(TX_WHITE);
            txSelectFont ("Comic Sans MS", 60);
            txDrawText(0,250,1920,1080,"   ����������:\n"
                       "W - ���� ����� \n"
                       "A - ���� �����\n"
                       "S - ���� ����\n"
                       "D - ���� ������\n" "\n"
                       "   ��������:\n"
                       "������� ������� � ������,������� �������� �� ��������\n" "\n");
            if( txMouseButtons() == 1 and
                btnEx.x < txMouseX() and txMouseX() < btnEx.w + btnEx.x and
                btnEx.y < txMouseY() and txMouseY() < btnEx.y + btnEx.h)
            {
                page = "menu";
            }
        }

        //����
        if(page == "street")
  n      {
            if(GetAsyncKeyState ('T'))
            {
                time = 1;
            }
            txBitBlt(txDC(),xL,yL,1920,1080,location);
            cat.drawCat();
            helf.draw();
            if (txMouseButtons() == 2 and
                1725 <= txMouseX() and txMouseX() <= 1805 and
                320 <= txMouseY() and txMouseY() <= 400 and
                1700 <= cat.x and cat.x <= 1775 and
                350 <= cat.y and cat.y <= 380)
            {
                page = "dom";
            }
            if (popil == true)
            {
                txTransparentBlt(txDC(),650,386,93,50,cat2,0,0,RGB(0,0,0));
                if(cat.x < 1130 and cat.y < 530)
                {
                    page = "�����";
                }
            }
            if(sten == true)
            {
                popil = false;
            }
            if(fight == true and time !=0)
            {
                ghost.draw(cat.x, cat.y);
                ghost1.draw(cat.x, cat.y);
                ghost2.draw(cat.x, cat.y);
                txSetColor(TX_WHITE);
                time -= 1;
                txSelectFont ("Comic Sans MS", 50);
                sprintf(str,"0:%d",time/10);
                txTextOut(340,240,str);

                if (((cat.x+30<ghost.x+ghost.w) &&
                    (cat.x+cat.w-30>ghost.x) &&
                    (cat.y+30<ghost.y+ghost.h) &&
                    (cat.y+cat.h-30>ghost.y)) or
                    ((cat.x+30<ghost1.x+ghost1.w) &&
                    (cat.x+cat.w-30>ghost1.x) &&
                    (cat.y+30<ghost1.y+ghost1.h) &&
                    (cat.y+cat.h-30>ghost1.y)) or
                    ((cat.x+30<ghost2.x+ghost2.w) &&
                    (cat.x+cat.w-30>ghost2.x) &&
                    (cat.y+30<ghost2.y+ghost2.h) &&
                    (cat.y+cat.h-30>ghost2.y)))
                {
                    helf.hp -= 1;
                }
            }
            if(fight == true and time <= 0)
            {
                txBitBlt(txDC(),0,0,1920,1080,end1);
                txTransparentBlt(txDC(),830,400, 886,600,sleep, 886*da, 0,RGB(150,150,100));
                time -= 1;
                da += 1;
                txSleep(150);
                if(da>3)
                {
                    da = 0;
                }
                if(time <= -50)
                {
                    page = "alone";
                }

            }
        }

        if(page == "dom")
        {
            if (sten == false and kvest == false and fight == false and done == false)
            {
                txBitBlt(txDC(),0,0,1920,1080,house);
                G.draw();
                DI.x = 550; DI.y = 475; DI.r = 50; DI.v = true; DI.text = "������ �������, ��� �� ��� �������?"; DI.draw();
                btnV1.draw();
                btnV2.draw();
                nKad=0;
                if( txMouseButtons() == 1 and
                        btnV1.x < txMouseX() and txMouseX() < btnV1.w + btnV1.x and
                        btnV1.y < txMouseY() and txMouseY() < btnV1.y + btnV1.h)
                    {
                        DI.text = "�� ����� ��������� �����, ����� \n" "� ���� ������� �����";  DI.draw();
                        G.n = 2;
                        txSleep(2000);
                        page = "havat";
                    }
                if( txMouseButtons() == 1 and
                        btnV2.x < txMouseX() and txMouseX() < btnV2.w + btnV2.x and
                        btnV2.y < txMouseY() and txMouseY() < btnV2.y + btnV2.h)
                    {
                        DI.text = "� ���� �� ������ �� ����\n" "� ���� � ���� ����������, ��� �� ����"; DI.draw();
                        G.n = 1;
                        txSleep(4500);
                        helf.hp = 0;
                    }
            }
            if(sten == true and page == "dom" and kvest == false and fight == false)
            {
                txBitBlt(txDC(),0,0,1920,1080,house);
                G.n = 0; G.draw();
                DI.x = 550; DI.y = 475; DI.r = 50;
                DI.text = "���� ��������, ������ ���� �e";  DI.draw();
                txSleep(1900);
                DI.text = "."; DI.draw();
                txSleep(750);
                DI.text = ".."; DI.draw();
                txSleep(750);
                DI.text = "..."; DI.draw();
                txSleep(750);
                DI.text = "...."; DI.draw();
                txSleep(750);
                DI.text = "Aaaa, �� ���������� ����� ������\n" "�� ���?"; DI.draw();
                vibor = true;
                while (vibor == true)
                {
                    txBegin();
                    txBitBlt(txDC(),0,0,1920,1080,house);
                    DI.draw();
                    c1.x = 340; c1.draw = true; c1.paint();
                    btnV1.text = "�������"; btnV2.text = "�������"; btnV1.r = 50; btnV2.r = 50; btnV1.draw(); btnV2.draw();
                    if( txMouseButtons() == 1 and
                        btnV1.x < txMouseX() and txMouseX() < btnV1.w + btnV1.x and
                        btnV1.y < txMouseY() and txMouseY() < btnV1.y + btnV1.h)
                    {
                        c1.draw = false;
                        txBitBlt(txDC(),0,0,1920,1080,house);
                        G.x = 150; G.draw();
                        DI.text = "�� ��� ������ ��� �� ���������� \n" "���� ��������� ������ ��� ���������"; DI.draw();
                        txSleep(3500);
                        DI.text = "��, ���������"; DI.draw();
                        txSleep(2500);
                        DI.text = "���� ���������� �����"; DI.draw();
                        txSleep(2500);
                        DI.text = "���� ������"; DI.draw();
                        txSleep(1500);
                        DI.text = "������ �� ����"; DI.draw();
                        txSleep(2500);
                        kvest = true;
                        vibor = false;
                        page = "kvest";

                    }
                    if( txMouseButtons() == 1 and
                        btnV2.x < txMouseX() and txMouseX() < btnV2.w + btnV2.x and
                        btnV2.y < txMouseY() and txMouseY() < btnV2.y + btnV2.h)
                    {
                        c1.draw = false;
                        G.x = 150; G.draw();
                        DI.text = "�, ������ ����������. �� ����� \n" "��� �����"; DI.draw();
                        txSleep(2500);
                        fight = true;
                        vibor = false;
                        page = "street";
                    }
                    txEnd();
                    txSleep(10);
                }
            }
            if(done == true)
            {
                txBitBlt(txDC(),0,0,1920,1080,house);
                G.n = 0; G.draw();
                DI.x = 550; DI.y = 475; DI.r = 50;
                DI.text = "��� ������, ��� ���� ���������";  DI.draw();
                txSleep(5555);
                if(point <3)
                {
                    DI.text = "��� ��� ��� ���";  DI.draw();
                    txSleep(3555);
                    DI.text = "��� ����, �� �� �� ������� \n" "���� � ����";  DI.draw();
                    txSleep(2555);
                    DI.text = "��������....";  DI.draw();
                    txSleep(2555);
                    page = "lose";
                }
                if(point >2)
                {
                    DI.text = "��� ��� ��� ���";  DI.draw();
                    txSleep(3555);
                    DI.text = "���������������";  DI.draw();
                    txSleep(2555);
                    DI.text = "� ���� ����������!\n" "�� ������ ���� �� ����!";  DI.draw();
                    txSleep(3555);
                    page = "victory";
                }
            }
        }

        if(page == "lose")
        {
            txSetFillColor(TX_BLACK);
            txClear();
            txTransparentBlt(txDC(),200,200, 800,800,Lose, 0, 0,RGB(0,0,255));
            txSelectFont ("Comic Sans MS", 150);
            txSetColor(TX_WHITE,4);
            txTextOut(980,310,"�� ��������!(");
            txSleep(4000);
            page = "exit";
        }
        if(page == "victory")
        {
            txSetFillColor(TX_BLACK);
            txClear();
            txTransparentBlt(txDC(),200,200, 800,800,Victory, 0, 0,RGB(0,255,0));
            txSelectFont ("Comic Sans MS", 150);
            txSetColor(TX_WHITE,4);
            txTextOut(980,310,"�� �������!)");
            txSleep(4000);
            page = "exit";
        }
        if(page == "alone")
        {
            txSetFillColor(TX_BLACK);
            txClear();
            txTransparentBlt(txDC(),200,200, 800,800,Alone, 0, 0,RGB(255,0,0));
            txSelectFont ("Comic Sans MS", 40);
            txSetColor(TX_WHITE,4);
            txDrawText(980,310,1500,800,"�� �� �������� �������\n" "� ���� ��������� ����������\n" "��������, �� �� ������� ����, ������ ����..." );
            txSleep(10000);
            page = "exit";
        }

        if(page == "havat")
        {
            popil = true;
            txBitBlt(txDC(),0,0,1920,1080,kushat);
            txTransparentBlt(txDC(),833,751, 375,257,plate, 375*nK, 0,RGB(0,0,255));
            if(txMouseButtons() == 1)
            {
                nK += 1;
            }
            if (nK > 4)
                {
                    txBitBlt(txDC(),0,0,1920,1080,house);
                    G.draw();
                    DI.text = "�� ��� �������"; DI.draw();
                    txSleep(2500);
                    page = "street";
                    helf.hp = 100;

                }


        }
        if(page == "�����")
        {
            txBitBlt(txDC(),xL,yL,1920,1080,location);
            nKad = 0;
            txTransparentBlt(txDC(),cat.x,cat.y, cat.w,cat.h,cat.image, 83.3*nKad, 0,RGB(150,150,100));
            txTransparentBlt(txDC(),650,386,93,50,cat2,0,0,RGB(0,0,0));
            DI.v = true;
            if(GetAsyncKeyState ('A') and cat.x > 820)
            {
                cat.image = cat.L;
                cat.x -= cat.v;
                nKad += 1;
                if (nKad>=3) nKad=0;
            }

            if (cat.x < 820 and kadr == 0)
            {
                DI.text = "?"; DI.x = 800; DI.y = 475;  DI.draw();
                c2.paint();
                txSleep(1000);
                DI.text = "�� ������ ���� ����� ���������, \n" "����� ���������� ����� �� ���� ���"; DI.draw();
                txSleep(3999);
                kadr = 1;
            }
            if(kadr == 1)
            {
                txClear();
                txBitBlt(txDC(),xL,yL,1920,1080,location);
                txTransparentBlt(txDC(),cat.x,cat.y, cat.w,cat.h,cat.image, 83.3*nKad, 0,RGB(150,150,100));
                txTransparentBlt(txDC(),650,386,93,50,cat2,0,0,RGB(0,0,0));
                c1.paint();
                DI.text = "���, �� ����� ����������� \n" "��� ������� �����-�� ���������"; DI.draw();
                txSleep(3999);
                kadr = 2;
            }
            if(kadr == 2)
            {
                c2.paint();
                DI.text = "�, ��� ���� ���������, ��� ���� ����� ������.\n" "������, ���� ����� ����� ������� � ������, �� ����� � ��� ������ ���� ��������� �����. \n " " ��� ����� � ������, ����� � ��� ��������� ����������"; DI.draw();
                txSleep(4500);
                sten = true;
            }
            if (sten == true)
            {
                page = "street";
            }
        }
        if(page == "kvest")
        {
        txBitBlt(txDC(),0,0,1920,1080,kv1);
        astr1.draw(cat.x,cat.y);
        astr2.draw(cat.x,cat.y);
        astr3.draw(cat.x,cat.y);
        astr4.draw(cat.x,cat.y);
        astr5.draw(cat.x,cat.y);
        astr6.draw(cat.x,cat.y);
        astr7.draw(cat.x,cat.y);
        astr8.draw(cat.x,cat.y);
        aloe1.draw(cat.x,cat.y);
        aloe2.draw(cat.x,cat.y);
        aloe3.draw(cat.x,cat.y);
        aloe4.draw(cat.x,cat.y);
        aloe5.draw(cat.x,cat.y);
        aloe6.draw(cat.x,cat.y);
        aloe7.draw(cat.x,cat.y);
        aloe8.draw(cat.x,cat.y);
        cact1.draw(cat.x,cat.y);
        cact2.draw(cat.x,cat.y);
        cact3.draw(cat.x,cat.y);
        cact4.draw(cat.x,cat.y);
        cact5.draw(cat.x,cat.y);
        cact6.draw(cat.x,cat.y);
        cact7.draw(cat.x,cat.y);
        cact8.draw(cat.x,cat.y);
        sun1.draw(cat.x,cat.y);
        sun2.draw(cat.x,cat.y);
        sun3.draw(cat.x,cat.y);
        sun4.draw(cat.x,cat.y);
        sun5.draw(cat.x,cat.y);
        sun6.draw(cat.x,cat.y);
        sun7.draw(cat.x,cat.y);
        sun8.draw(cat.x,cat.y);
        done = true;
        sq.draw();
        cat.drawCat();
        if(sq.x<cat.x and sq.x+sq.w>cat.x and sq.y<cat.y and sq.y+sq.h>cat.y and txMouseButtons() == 1)
        {
            while(txMouseButtons() == 1)
            {
                txSleep(5);
            }
            time = 3;
        }
        if(astr1.n>=1 or astr2.n>=1 or astr3.n>=1 or astr4.n>=1 or astr5.n>=1 or astr6.n>=1 or astr7.n>=1 or astr8.n>=1)
        {
            astr1.n = 0; astr2.n = 0; astr3.n = 0; astr4.n = 0; astr5.n = 0; astr6.n = 0; astr7.n = 0; astr8.n = 0;
            nA += 1;
        }
        if(aloe1.n>=1 or aloe2.n>=1 or aloe3.n>=1 or aloe4.n>=1 or aloe5.n>=1 or aloe6.n>=1 or aloe7.n>=1 or aloe8.n>=1)
        {
            aloe1.n = 0;aloe2.n = 0;aloe3.n = 0;aloe4.n = 0;aloe5.n = 0;aloe6.n = 0;aloe7.n = 0;aloe8.n = 0;
            nAl += 1;
        }
        if(cact1.n >= 1 or cact2.n >= 1 or cact3.n >= 1 or cact4.n >= 1 or cact5.n >= 1 or cact6.n >= 1 or cact7.n >= 1 or cact8.n >= 1)
        {
            cact1.n = 0;cact2.n = 0;cact3.n = 0;cact4.n = 0;cact5.n = 0;cact6.n = 0;cact7.n = 0;cact8.n = 0;
            nC += 1;
        }
        if(sun1.n >= 1 or sun2.n >= 1 or sun3.n >= 1 or sun4.n >= 1 or sun5.n >= 1 or sun6.n >= 1 or sun7.n >= 1 or sun8.n >= 1)
        {
            sun1.n = 0;sun2.n = 0;sun3.n = 0;sun4.n = 0;sun5.n = 0;sun6.n = 0;sun7.n = 0;sun8.n = 0;
            nP += 1;
        }
        if(task1 == true and task2 == false and task3 == false and task4 == false and task == false)
        {
            G.draw();
            DI.x = 550; DI.y = 475; DI.r = 50; DI.v = true; DI.text = "������ ����� ���������!"; DI.draw();
            txSleep(2500);
            DI.text = "�� ���, ���������!"; DI.draw();
            txSleep(2000);
            DI.text = "������� ��� 3 �����, \n" "1 ���������, 2 ����, 1 ������"; DI.draw();
            txSleep(5000);
            DI.v = false; G.v = false;
            time = 300;
            task = true;
        }
        if(task1 == false and task2 == true and task3 == false and task4 == false and task == false)
        {
            astr1.v = true; astr2.v = true; astr3.v = true; astr4.v = true; astr5.v = true; astr6.v = true; astr7.v = true; astr8.v = true; aloe1.v = true;aloe2.v = true;aloe3.v = true;aloe4.v = true;aloe5.v = true;aloe6.v = true;aloe7.v = true;aloe8.v = true; cact1.v = true;cact2.v = true;cact3.v = true;cact4.v = true;cact5.v = true;cact6.v = true;cact7.v = true;cact8.v = true;  sun1.v = true;sun2.v = true;sun3.v = true;sun4.v = true;sun5.v = true;sun6.v = true;sun7.v = true;sun8.v = true;
            nA = 0; nP = 0; nAl = 0; nC = 0;
            G.v = true; G.draw();
            DI.x = 550; DI.y = 475; DI.r = 50; DI.v = true; DI.text = "������ ������ �������"; DI.draw();
            txSleep(2500);
            DI.text = "������� ��� 2 �����, \n" "4 ���������a, 1 ����, 3 ������a"; DI.draw();
            txSleep(5000);
            DI.v = false; G.v = false;
            time = 300;
            task = true;
        }
        if(task1 == false and task2 == false and task3 == true and task4 == false and task == false)
        {
            astr1.v = true; astr2.v = true; astr3.v = true; astr4.v = true; astr5.v = true; astr6.v = true; astr7.v = true; astr8.v = true; aloe1.v = true;aloe2.v = true;aloe3.v = true;aloe4.v = true;aloe5.v = true;aloe6.v = true;aloe7.v = true;aloe8.v = true; cact1.v = true;cact2.v = true;cact3.v = true;cact4.v = true;cact5.v = true;cact6.v = true;cact7.v = true;cact8.v = true;  sun1.v = true;sun2.v = true;sun3.v = true;sun4.v = true;sun5.v = true;sun6.v = true;sun7.v = true;sun8.v = true;
            G.v = true; G.draw();
            nA = 0; nP = 0; nAl = 0; nC = 0;
            DI.x = 550; DI.y = 475; DI.r = 50; DI.v = true; DI.text = "������ ������ �������"; DI.draw();
            txSleep(2500);
            DI.text = "������� ��� 4 �����, \n" "5 �����������, 3 ����, 6 ��������"; DI.draw();
            txSleep(5000);
            DI.v = false; G.v = false;
            time = 450;
            task = true;        }
        if(task1 == false and task2 == false and task3 == false and task4 == true and task == false)
        {
            astr1.v = true; astr2.v = true; astr3.v = true; astr4.v = true; astr5.v = true; astr6.v = true; astr7.v = true; astr8.v = true; aloe1.v = true;aloe2.v = true;aloe3.v = true;aloe4.v = true;aloe5.v = true;aloe6.v = true;aloe7.v = true;aloe8.v = true; cact1.v = true;cact2.v = true;cact3.v = true;cact4.v = true;cact5.v = true;cact6.v = true;cact7.v = true;cact8.v = true;  sun1.v = true;sun2.v = true;sun3.v = true;sun4.v = true;sun5.v = true;sun6.v = true;sun7.v = true;sun8.v = true;
            G.v = true; G.draw();
            nA = 0; nP = 0; nAl = 0; nC = 0;
            DI.x = 550; DI.y = 475; DI.r = 50; DI.v = true; DI.text = "������ ��������� �������"; DI.draw();
            txSleep(2500);
            DI.text = "������ ������ ��� �����!"; DI.draw();
            txSleep(5000);
            DI.v = false; G.v = false;
            time = 600;
            task = true;
        }
        if(task1 == true and task == true)
        {
            txBegin();
            txSetColor(TX_BLACK);
            txSelectFont ("Comic Sans MS", 50);
            sprintf(str,"0:%d",time/10);
            txTextOut(700,123,str);
            if(nA == 3 and nP == 1 and nAl == 2 and nC == 1 and time==1)
            {
                G.v = true; DI.v = true; G.draw();
                DI.text = "�o�����!"; DI.draw();
                txSleep(2500);
                point ++;
                task = false;
                task1 = false;
                task2 = true;

            }
            if(nA != 3 and nP != 1 and nAl != 2 and nC != 1 and time==1)
            {
                G.v = true; G.draw();
                DI.v = true; DI.text = "� ���� �� ����������"; DI.draw();
                txSleep(1500);
                nA = 0; nP = 0; nAl = 0; nC = 0;
                time = 300;
                task = false;
                task1 = false;
                task2 = true;
            }
            txEnd();
            time -= 1;

        }
        if(task2 == true and task == true)
        {
            txBegin();
            txSetColor(TX_BLACK);
            txSelectFont ("Comic Sans MS", 50);
            sprintf(str,"0:%d",time/10);
            txTextOut(700,123,str);
            if(nA == 2 and nP == 4 and nAl == 1 and nC == 3 and time<=1)
            {
                G.v = true; DI.v = true; G.draw();
                DI.text = "�o�����!"; DI.draw();
                txSleep(2500);
                point ++;
                task = false;
                task2 = false;
                task3 = true;

            }
            if(nA != 2 and nP != 4 and nAl != 1 and nC != 3 and time<=1)
            {
                G.v = true; G.draw();
                DI.v = true; DI.text = "� ���� �� ����������"; DI.draw();
                txSleep(1500);
                nA = 0; nP = 0; nAl = 0; nC = 0;
                task = false;
                task2 = false;
                task3 = true;
            }
            txEnd();
            time -= 1;
        }
        if(task3 == true and task == true)
        {
            txBegin();
            txSetColor(TX_BLACK);
            txSelectFont ("Comic Sans MS", 50);
            sprintf(str,"0:%d",time/10);
            txTextOut(700,123,str);
            if(nA == 4 and nP == 5 and nAl == 3 and nC == 6 and time==1)
            {
                G.v = true; DI.v = true; G.draw();
                DI.text = "�������!"; DI.draw();
                txSleep(2500);
                point ++;
                time = 150;
                task = false;
                task3 = false;
                task4 = true;

            }
            if(nA != 2 and nP != 4 and nAl != 1 and nC != 3 and time==1)
            {
                G.v = true; G.draw();
                DI.v = true; DI.text = "� ���� �� ����������" ; DI.draw();
                txSleep(1500);
                nA = 0; nP = 0; nAl = 0; nC = 0;
                time = 150;
                task = false;
                task3 = false;
                task4 = true;
            }
            txEnd();
            time -= 1;
        }
        if(task4 == true and task == true)
        {
            txBegin();
            txSetColor(TX_BLACK);
            txSelectFont ("Comic Sans MS", 50);
            sprintf(str,"0:%d",time/10);
            txTextOut(700,123,str);
            if(nA == 8 and nP == 8 and nAl == 8 and nC == 8 and time==1)
            {
                G.v = true; DI.v = true; G.draw();
                DI.text = "�������, ������ �������� �����\n" "������ �����"; DI.draw();
                txSleep(2500);
                point ++;
                task4 = false;
                done = true;
                page = "dom";
            }
            if(nA != 8 and nP != 8 and nAl != 8 and nC != 8 and time==1)
            {
                G.v = true; G.draw();
                DI.v = true; DI.text = "� ���� �� ����������, ������ �������� �����\n" "������ �����"; DI.draw();
                txSleep(2500);
                task4 = false;
                done = true;
                page = "dom";
            }
            txEnd();
            time -= 1;
        }
        }


        txEnd();
        txSleep(10);

    }
txDeleteDC(cat.image);
txDeleteDC(cat.U);
txDeleteDC(cat.D);
txDeleteDC(cat.L);
txDeleteDC(cat.R);
txDeleteDC(cat.RU);
txDeleteDC(cat.RD);
txDeleteDC(cat.LU);
txDeleteDC(cat.LD);
txDeleteDC(location);
txDeleteDC(DI.image);
txDeleteDC(G.image);
txDeleteDC(Lose);
txDeleteDC(plate);
txDeleteDC(kushat);
txDeleteDC(cat2);
txDeleteDC(c1.image);
txDeleteDC(c2.image);
txDeleteDC(helf.image);
txDeleteDC(ghost.L);
txDeleteDC(ghost.R);
txDeleteDC(ghost.image);
txDeleteDC(Victory);
txDeleteDC(Alone);
txDisableAutoPause();
txTextCursor (false);
return 0;
}

