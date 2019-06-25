#include<math.h>   
#include<iomanip>    
#include<stdlib.h>    
#include<windows.h>   
#include<stdio.h>    
#include<stdlib.h>   
#include<iostream>    
#include<fstream>
using namespace std;
#define PI 3.1415926

unsigned char *pBmpBuf;//����ͼ�����ݵ�ָ��

int bmpWidth;//ͼ��Ŀ�   
int bmpHeight;//ͼ��ĸ�   
RGBQUAD *pColorTable;//��ɫ��ָ�� 

int biBitCount;//ͼ�����ͣ�ÿ����λ��   
  

//��ͼ���λͼ���ݡ����ߡ���ɫ��ÿ����λ�������ݽ��ڴ棬�������Ӧ��ȫ�ֱ�����   
bool readBmp(char *bmpName)   
{  
    FILE *fp=fopen(bmpName,"rb");//�����ƶ���ʽ��ָ����ͼ���ļ�   
  
    if(fp==0)  
        return 0;  
  
    //����λͼ�ļ�ͷ�ṹBITMAPFILEHEADER   
  
    fseek(fp, sizeof(BITMAPFILEHEADER),0);  
 
    //����λͼ��Ϣͷ�ṹ��������ȡλͼ��Ϣͷ���ڴ棬����ڱ���head��   
  
   BITMAPINFOHEADER head;    
  
   fread(&head, sizeof(BITMAPINFOHEADER), 1,fp); //��ȡͼ����ߡ�ÿ������ռλ������Ϣ   
  
    bmpWidth = head.biWidth;  
  
    bmpHeight = head.biHeight;  
  
    biBitCount = head.biBitCount;//�������������ͼ��ÿ��������ռ���ֽ�����������4�ı�����   
  
    int lineByte=(bmpWidth * biBitCount/8+3)/4*4;//�Ҷ�ͼ������ɫ������ɫ�����Ϊ256   
  
    if(biBitCount==8)  
    {  
  
       //������ɫ������Ҫ�Ŀռ䣬����ɫ����ڴ�   
  
        pColorTable=new RGBQUAD[256];  
  
        fread(pColorTable,sizeof(RGBQUAD),256,fp);  
  
    }  
  
    //����λͼ��������Ҫ�Ŀռ䣬��λͼ���ݽ��ڴ�   
 
    pBmpBuf=new unsigned char[lineByte * bmpHeight];  
  
    fread(pBmpBuf,1,lineByte * bmpHeight,fp);  
  
    fclose(fp);//�ر��ļ�   
 
    return 1;//��ȡ�ļ��ɹ�   
}  

//����һ��ͼ��λͼ���ݡ����ߡ���ɫ��ָ�뼰ÿ������ռ��λ������Ϣ,����д��ָ���ļ���   
bool saveBmp(char *bmpName, unsigned char *imgBuf, int width, int height, int biBitCount, RGBQUAD *pColorTable)  
{  
  
    //���λͼ����ָ��Ϊ0����û�����ݴ��룬��������   
 
    if(!imgBuf)  
       return 0;  
  
    //��ɫ���С�����ֽ�Ϊ��λ���Ҷ�ͼ����ɫ��Ϊ1024�ֽڣ���ɫͼ����ɫ���СΪ0   
  
    int colorTablesize=0;  
  
    if(biBitCount==8)  
        colorTablesize=1024;  
  
    //���洢ͼ������ÿ���ֽ���Ϊ4�ı���   
  
    int lineByte=(width * biBitCount/8+3)/4*4;  
  
    //�Զ�����д�ķ�ʽ���ļ�   
  
    FILE *fp=fopen(bmpName,"wb");  
  
    if(fp==0)  
        return 0;  
  
    //����λͼ�ļ�ͷ�ṹ��������д�ļ�ͷ��Ϣ    
  
    BITMAPFILEHEADER fileHead;  
  
    fileHead.bfType = 0x4D42;//bmp����   
  
   //bfSize��ͼ���ļ�4����ɲ���֮��    
  
    fileHead.bfSize= sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + colorTablesize + lineByte*height;  
  
    fileHead.bfReserved1 = 0;  
  
    fileHead.bfReserved2 = 0;  
  
    //bfOffBits��ͼ���ļ�ǰ3����������ռ�֮��   
  
    fileHead.bfOffBits=54+colorTablesize;  
 
    //д�ļ�ͷ���ļ�   
 
    fwrite(&fileHead, sizeof(BITMAPFILEHEADER),1, fp);  
  
    //����λͼ��Ϣͷ�ṹ��������д��Ϣͷ��Ϣ    
  
    BITMAPINFOHEADER head;   
  
    head.biBitCount=biBitCount;  
  
   head.biClrImportant=0;  
  
    head.biClrUsed=0;  
  
    head.biCompression=0;  
  
    head.biHeight=height;  
  
    head.biPlanes=1;  
  
    head.biSize=40;  
  
    head.biSizeImage=lineByte*height;  
  
    head.biWidth=width;  
  
    head.biXPelsPerMeter=0;  
  
    head.biYPelsPerMeter=0;  
  
    //дλͼ��Ϣͷ���ڴ�   
  
    fwrite(&head, sizeof(BITMAPINFOHEADER),1, fp);  
  
    //����Ҷ�ͼ������ɫ��д���ļ�     
  
    if(biBitCount==8)  
        fwrite(pColorTable, sizeof(RGBQUAD),256, fp);  
  
    //дλͼ���ݽ��ļ�   
  
    fwrite(imgBuf, height*lineByte, 1, fp);  
  
    //�ر��ļ�   
 
   fclose(fp);  
  
    return 1;  
 
}  


//����Ϊ���صĶ�ȡ����   
void doIt()  
{  
  
    //����ָ��BMP�ļ����ڴ�   
  
    char readPath[]="9ebb0c3dbfdfb9b483695a772441e66d.BMP";  
  
    readBmp(readPath);  
  
    //���ͼ�����Ϣ   
 
   // cout<<"width="<<bmpWidth<<" height="<<bmpHeight<<" biBitCount="<<biBitCount<<endl;  
      
    //ѭ��������ͼ�������   
  
    //ÿ���ֽ���     
 /*CWnd *pWnd=GetDlgItem(IDC_PICTURE);//���pictrue�ؼ����ڵľ��    
 CRect rect;    
 pWnd->GetClientRect(&rect);//���pictrue�ؼ����ڵľ�������    
 CDC *pDC=pWnd->GetDC();//���pictrue�ؼ���DC       
 //��ʾͼƬ    
 pDC->SetStretchBltMode(COLORONCOLOR);     
 StretchDIBits(pDC->GetSafeHdc(),0,0,rect.Width(),rect.Height(),0,0,bmpWidth,bmpHeight,pBmpData,pBmpInfo,DIB_RGB_COLORS,SRCCOPY);*/
    cout<<"        ";
	for(int i=0;i<30;i++)   
  	printf("===");
  	cout<<endl;
	cout<<"        ||  ";
   int lineByte=(bmpWidth*biBitCount/8+3)/4*4;  
  
    //ѭ����������Բ�ɫͼ�񣬱���ÿ���ص���������    
  
    int m=0,n=0,count_xiang_su=0,choose;  
  	cout<<"       ��ѡ���ͼƬ���еĲ���: 1ȱʧƽ�Ʊ任 2��ת�任 3��ȱʧƽ�Ʊ任                ||\n";
  	cin>>choose;
    //��ͼ�����½�1/4�����óɺ�ɫ   
   
  /* ofstream outfile("ͼ������.txt",ios::in|ios::trunc);  
  
   if(biBitCount==8) //���ڻҶ�ͼ��   
    {                
    //------------------------------------------------------------------------------------   
    //�������ͼ��ķָ��8*8С��Ԫ����������ֵ�洢��ָ���ı��С�����BMPͼ������������Ǵ�   
    //���½ǣ��������ң�������������ɨ���    
        int L1=0;  
       int hang=63;  
        int lie=0;  
        //int L2=0;   
        //int fen_ge=8;   
        for(int fen_ge_hang=0;fen_ge_hang<8;fen_ge_hang++)//64*64������ѭ��   
        {   
            for(int fen_ge_lie=0;fen_ge_lie<8;fen_ge_lie++)//64*64�о���ѭ��   
            {   
            //--------------------------------------------   
                for(L1=hang;L1>hang-8;L1--)//8*8������   
                {  
                    for(int L2=lie;L2<lie+8;L2++)//8*8������   
                    {  
                        m=*(pBmpBuf+L1*lineByte+L2);  
                        outfile<<m<<" ";  
                        count_xiang_su++;  
                        if(count_xiang_su%8==0)//ÿ8*8��������ı��ļ�   
                        {  
                            outfile<<endl;  
                        }  
                    }  
                }  
            //---------------------------------------------   
                hang=63-fen_ge_hang*8;//64*64�����б任   
                lie+=8;//64*64�����б任   
                    //��һ�У�64����8��8*8����������    
            }  
            hang-=8;//64*64������б任   
            lie=0;//64*64juzhen   
        }  
    }  
  
   //double xiang_su[2048];    
    //ofstream outfile("xiang_su_zhi.txt",ios::in|ios::trunc);   
    if(!outfile)  
    {  
        cout<<"open error!"<<endl;  
        exit(1);  
    }  */
    if(choose==2)
    {
    	int i,j,x,y,x2,y2,intex,intey,original_point_A,original_point_B,original_point_C,original_point_D,m,n;
    	double x1,y1,decix,deciy;
    	double p;
    	cout<<"��������ת�Ƕ�:";
    	cin>>p;
    	if ((int)p % 360 == 270){
        p ++;
	    }

    	p=(double)(p*PI/180);
    	int newwidth,newheigh;
    	newwidth=abs(bmpWidth * cos(p) + bmpHeight * sin(p));
		newheigh=abs(bmpWidth * sin(p) + bmpHeight * cos(p));
    	//cout<<bmpWidth<<" "<<bmpHeight<<endl<<newwidth<<" "<<newheigh<<endl;
    	int newlineByte=(newwidth * biBitCount/8+3)/4*4;
    	unsigned char *newpBmpBuf;
		newpBmpBuf=new unsigned char[newlineByte * newheigh];
    	x=newwidth/2;
    	y=newheigh/2;
    	x2=bmpWidth/2;
    	y2=bmpHeight/2;
    	//cout<<x<<" "<<y<<" "<<x2<<" "<<y2<<endl;
    	for(i=0;i<newheigh;i++)  
        {  
            for(j=0;j<newwidth;j++)  
            {  
            	y1=(i-y)*cos(-p)+(j-x)*sin(-p);
            	x1=(j-x)*cos(-p)-(i-y)*sin(-p);
            	if(abs(x1)+x2<bmpWidth&&abs(y1)+y2<bmpHeight)
            	{
            	intex=x1+x2;
            	intey=y1+y2;
            	/*decix=x1-intex;
				deciy=y1-intey;
				original_point_A = intey * lineByte + intex * 3;
                original_point_B = intey * lineByte + (intex + 1) * 3;
				original_point_C = (intey + 1) * lineByte + intex * 3;
                original_point_D = (intey + 1) * lineByte + (intex + 1)*3;
         		if (intex == bmpWidth - 1){
                    // cout << "hhhhh" << endl;
                    original_point_B = original_point_A;
                    original_point_D = original_point_C;
                }
                if (intey == bmpHeight - 1){
                    original_point_C = original_point_A;
                    original_point_D = original_point_B;
                }

                for(int k=0;k<3;k++)   
               {  
 					*(newpBmpBuf+i*newlineByte+j*3+k)=(1-deciy)*(1-decix)**(pBmpBuf+original_point_A+k)+(1-deciy)*decix**(pBmpBuf+original_point_C+k)+deciy*(1-decix)**(pBmpBuf+original_point_B+k)+deciy*decix**(pBmpBuf+original_point_D+k);
                }*/
                for(int k=0;k<3;k++)   
               {  
 					*(newpBmpBuf+i*newlineByte+j*3+k)=*(pBmpBuf+intey * lineByte + intex * 3+k);
 				}
                continue;
				}
 				 for(int k=0;k<3;k++) 
 				 *(newpBmpBuf+i*newlineByte+j*3+k)=0;
            }  
  
  
        }
        char writePath[]="nvcpy.BMP";//ͼƬ������ٴ洢   
  
    saveBmp(writePath, newpBmpBuf, newwidth, newheigh, biBitCount, pColorTable);  
  
    //�����������pBmpBuf��pColorTable��ȫ�ֱ��������ļ�����ʱ����Ŀռ�   
  
    delete []pBmpBuf;  
  
    if(biBitCount==8)  
        delete []pColorTable;  
    cout<<"��תͼƬ���!"; 
        
    return;
		  
	}
	else if(choose==3)
	{
	int yhei,hei,ywid,wid,newHeight,newWidth,newlineByte;
	cout<<"����������Ҫƽ�Ƹ߶�(����Ϊ���ƣ�����Ϊ����):";
	cin>>yhei;
	hei=fabs(yhei);
	cout<<"����������Ҫƽ�ƿ��(����Ϊ���ƣ�����Ϊ����):";
	cin>>ywid;
	unsigned char *newpBmpBuf;
	wid=fabs(ywid);
	newHeight=bmpHeight+hei;
	newWidth=bmpWidth+wid;
	newlineByte=lineByte+wid*3;
	newpBmpBuf=new unsigned char[(lineByte+wid*3) * (bmpHeight+hei)];	   
    int i,j,k;
    if(yhei<=0)
    {
    for(i=0;i<newHeight-hei;i++)
    {
    	if(ywid<=0)
		{	
    	for(j=0;j<newWidth-wid;j++)  
            {  
                for(k=0;k<3;k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ   
               {  
                    *(newpBmpBuf+i*newlineByte+j*3+k)=*(pBmpBuf+i*lineByte+j*3+k);   
                }
            }  
    	}
    	else
    	{
        for(j=newWidth-1;j>=wid;j--)  
            {  
                for(k=0;k<3;k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ   
               {  
                    *(newpBmpBuf+i*newlineByte+j*3+k)=*(pBmpBuf+i*lineByte+(j-wid)*3+k);   
                }
            } 
		}
	}
	for(i=newHeight-1;i>=newHeight-hei;i--)
	{
		 for(int j=0;j<newWidth;j++)  
            {  
                for(int k=0;k<3;k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ   
               {  
               		*(newpBmpBuf+i*newlineByte+j*3+k)=0;
               }
        	}
	 }
    	if(ywid>0)
		{	
    	for(j=0;j<wid;j++)  
            {
				for(int i=0;i<newHeight-hei;i++)
				{  
                for(k=0;k<3;k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ   
               {  
                    *(newpBmpBuf+i*newlineByte+j*3+k)=0;   
                }
            	}
            }  
    	}
    	else
    	{
        for(j=newWidth-1;j>=newWidth-wid;j--)  
            {  
            	for(int i=0;i<newHeight-hei;i++)
				{  
                for(k=0;k<3;k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ   
               {  
                    *(newpBmpBuf+i*newlineByte+j*3+k)=0;   
                }
            	}
            } 
		} 
	}
    else
    {
	for(i=newHeight-1;i>=hei;i--)  
        {  
			if(ywid<=0)
		{	
			for(j=0;j<newWidth-wid;j++)  
            {  
                for(k=0;k<3;k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ   
               {  
                   *(newpBmpBuf+i*newlineByte+j*3+k)=*(pBmpBuf+(i-hei)*lineByte+j*3+k);   
                }
            }
		}
			else
			{
            for(j=newWidth-1;j>=wid;j--)  
            {  
                for(k=0;k<3;k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ   
               {  
                    *(newpBmpBuf+i*newlineByte+j*3+k)=*(pBmpBuf+(i-hei)*lineByte+(j-wid)*3+k);   
                }
            }
			}
		}
	for(i=0;i<hei;i++)
	{
		 for(j=0;j<newWidth;j++)  
            {  
                for(int k=0;k<3;k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ   
               {  
               		*(newpBmpBuf+i*newlineByte+j*3+k)=0;
               }
        	}
	 }
	if(ywid>0)
		{	
    	for(j=0;j<wid;j++)  
            {
				for(i=newHeight-1;i>=hei;i--)
				{  
                for(k=0;k<3;k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ   
               {  
                    *(newpBmpBuf+i*newlineByte+j*3+k)=0;   
                }
            	}
            }  
    	}
    	else
    	{
        for(j=newWidth-1;j>=newWidth-wid;j--)  
            {  
            	for(i=newHeight-1;i>=hei;i--)
				{  
                for(k=0;k<3;k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ   
               {  
                    *(newpBmpBuf+i*newlineByte+j*3+k)=0;   
                }
            	}
            } 
		} 
  
    }
       /* for(int i=0;i<bmpHeight;i++)  
        {  
            for(int j=0;j<bmpWidth;j++)  
            {  
                for(int k=0;k<3;k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ   
               {  
                    //*(pBmpBuf+i*lineByte+j*3+k)-=40;   
                   m=*(pBmpBuf+i*lineByte+j*3+k); 
                    outfile<<m<<" ";  
                    count_xiang_su++;  
                    if(count_xiang_su%8==0)  
                   {  
                        outfile<<endl;  
                    }  
                //n++;   
                }  
                n++;  
            }  
  
  
        }  
        cout<<"�ܵ����ظ���Ϊ:"<<n<<endl;  
        cout<<"----------------------------------------------------"<<endl;  */
        
    char writePath[]="nvcpy.BMP";//ͼƬ������ٴ洢   
  
    saveBmp(writePath, newpBmpBuf, newWidth, newHeight, biBitCount, pColorTable);  
  
    //�����������pBmpBuf��pColorTable��ȫ�ֱ��������ļ�����ʱ����Ŀռ�   
  
    delete []pBmpBuf;  
  
    if(biBitCount==8)  
        delete []pColorTable;  
    cout<<"ƽ��ͼƬ��ɣ�"; 
    return;
	}
    else if(choose==1)  
    {//��ɫͼ��
	int yhei,hei,ywid,wid;
	cout<<"����������Ҫƽ�Ƹ߶�(����Ϊ���ƣ�����Ϊ����):";
	cin>>yhei;
	hei=fabs(yhei);
	cout<<"����������Ҫƽ�ƿ��(����Ϊ���ƣ�����Ϊ����):";
	cin>>ywid;
	wid=fabs(ywid);	   
    int i,j,k;
    if(yhei<=0)
    {
    for(i=0;i<bmpHeight-hei;i++)
    {
    	if(ywid<=0)
		{	
    	for(j=0;j<bmpWidth-wid;j++)  
            {  
                for(k=0;k<3;k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ   
               {  
                    *(pBmpBuf+i*lineByte+j*3+k)=*(pBmpBuf+(i+hei)*lineByte+(j+wid)*3+k);   
                }
            }  
    	}
    	else
    	{
        for(j=bmpWidth-1;j>=wid;j--)  
            {  
                for(k=0;k<3;k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ   
               {  
                    *(pBmpBuf+i*lineByte+j*3+k)=*(pBmpBuf+(i+hei)*lineByte+(j-wid)*3+k);   
                }
            } 
		}
	}
	for(i=bmpHeight-1;i>=bmpHeight-hei;i--)
	{
		 for(int j=0;j<bmpWidth;j++)  
            {  
                for(int k=0;k<3;k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ   
               {  
               		*(pBmpBuf+i*lineByte+j*3+k)=0;
               }
        	}
	 }
    	if(ywid>0)
		{	
    	for(j=0;j<wid;j++)  
            {
				for(int i=0;i<bmpHeight-hei;i++)
				{  
                for(k=0;k<3;k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ   
               {  
                    *(pBmpBuf+i*lineByte+j*3+k)=0;   
                }
            	}
            }  
    	}
    	else
    	{
        for(j=bmpWidth-1;j>=bmpWidth-wid;j--)  
            {  
            	for(int i=0;i<bmpHeight-hei;i++)
				{  
                for(k=0;k<3;k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ   
               {  
                    *(pBmpBuf+i*lineByte+j*3+k)=0;   
                }
            	}
            } 
		} 
	}
    else
    {
	for(i=bmpHeight-1;i>=hei;i--)  
        {  
			if(ywid<=0)
		{	
			for(j=0;j<bmpWidth-wid;j++)  
            {  
                for(k=0;k<3;k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ   
               {  
                    *(pBmpBuf+i*lineByte+j*3+k)=*(pBmpBuf+(i-hei)*lineByte+(j+wid)*3+k);   
                }
            }
		}
			else
			{
            for(j=bmpWidth-1;j>=wid;j--)  
            {  
                for(k=0;k<3;k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ   
               {  
                    *(pBmpBuf+i*lineByte+j*3+k)=*(pBmpBuf+(i-hei)*lineByte+(j-wid)*3+k);   
                }
            }
			}
		}
	for(i=0;i<hei;i++)
	{
		 for(j=0;j<bmpWidth;j++)  
            {  
                for(int k=0;k<3;k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ   
               {  
               		*(pBmpBuf+i*lineByte+j*3+k)=0;
               }
        	}
	 }
	if(ywid>0)
		{	
    	for(j=0;j<wid;j++)  
            {
				for(i=bmpHeight-1;i>=hei;i--)
				{  
                for(k=0;k<3;k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ   
               {  
                    *(pBmpBuf+i*lineByte+j*3+k)=0;   
                }
            	}
            }  
    	}
    	else
    	{
        for(j=bmpWidth-1;j>=bmpWidth-wid;j--)  
            {  
            	for(i=bmpHeight-1;i>=hei;i--)
				{  
                for(k=0;k<3;k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ   
               {  
                    *(pBmpBuf+i*lineByte+j*3+k)=0;   
                }
            	}
            } 
		} 
  
    }
       /* for(int i=0;i<bmpHeight;i++)  
        {  
            for(int j=0;j<bmpWidth;j++)  
            {  
                for(int k=0;k<3;k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ   
               {  
                    //*(pBmpBuf+i*lineByte+j*3+k)-=40;   
                   m=*(pBmpBuf+i*lineByte+j*3+k); 
                    outfile<<m<<" ";  
                    count_xiang_su++;  
                    if(count_xiang_su%8==0)  
                   {  
                        outfile<<endl;  
                    }  
                //n++;   
                }  
                n++;  
            }  
  
  
        }  
        cout<<"�ܵ����ظ���Ϊ:"<<n<<endl;  
        cout<<"----------------------------------------------------"<<endl;  */
        cout<<"ƽ��ͼƬ��ɣ�"; 
    }  
    else
    {
    	cout<<"�������,��Ϊԭͼ\n"; 
	}
      
    //��ͼ�����ݴ���   
      
    char writePath[]="nvcpy.BMP";//ͼƬ������ٴ洢   
  
    saveBmp(writePath, pBmpBuf, bmpWidth, bmpHeight, biBitCount, pColorTable);  
  
    //�����������pBmpBuf��pColorTable��ȫ�ֱ��������ļ�����ʱ����Ŀռ�   
  
    delete []pBmpBuf;  
  
    if(biBitCount==8)  
        delete []pColorTable;  
}  


int main()
{
	doIt(); 
	cout<<"\n----------------------------------------------------"<<endl;
	return 0;
} 
