#include<iostream>
#include<string>
using namespace std;
/*
���D����:
���y�r�� �P�ɰO���Ѽ�
1.��e�P�e�@�Ӫ����A�ܤ�(�j�p�g)
2.�s���
3.�ثe�r�����
4.�̤j�r�����
*/
int main()
{
    /*a~z=97~122  A~Z=65~90*/
    int k;string s;
    while(cin>>k)
    {
        cin>>s;
        int c=0,maxl=0,nowl=0,i=0;
        bool A;
        if(90>=s.at(i)&&s.at(i)>=65)
        {
            A=true;
            c++;
            if(c==k)
            {
                nowl=nowl+k;
                maxl=max(maxl,nowl);
            }
        }
        else if(122>=s.at(i)&&s.at(i)>=97)
        {
            A=false;
            c++;
            if(c==k)
            {
                nowl=nowl+k;
                maxl=max(maxl,nowl);
            }
        }
        for(i=1;i<s.size();i++)
        {
            if(90>=s.at(i)&&s.at(i)>=65&&A)
            {
                c++;
                if(c==k)
                {
                    nowl=nowl+k;
                    maxl=max(maxl,nowl);
                }
                else if(c>k)
                {
                    nowl=k;
                }
            }
            else if(122>=s.at(i)&&s.at(i)>=97&&(!A))
            {
                c++;
                if(c==k)
                {
                    nowl=nowl+k;
                    maxl=max(maxl,nowl);
                }
                else if(c>k)
                {
                    nowl=k;
                }
            }
            else if(90>=s.at(i)&&s.at(i)>=65&&(!A))
            {
                if(k>c)
                {
                    nowl=0;
                }
                c=1;A=true;
                if(c==k)
                {
                    nowl=nowl+k;
                    maxl=max(maxl,nowl);
                }
                else if(c>k)
                {
                    nowl=k;
                }
            }
            else if(122>=s.at(i)&&s.at(i)>=97&&A)
            {
                if(k>c)
                {
                    nowl=0;
                }
                c=1;A=false;
                if(c==k)
                {
                    nowl=nowl+k;
                    maxl=max(maxl,nowl);
                }
                else if(c>k)
                {
                    nowl=k;
                }
            }
        }
        maxl=max(maxl,nowl);
        cout<<maxl<<endl;
    }
}
