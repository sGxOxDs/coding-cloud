#include<iostream>
#include<string>
using namespace std;
/*
解題概念:
掃描字串 同時記錄參數
1.當前與前一個的狀態變化(大小寫)
2.連續性
3.目前字串長度
4.最大字串長度
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
