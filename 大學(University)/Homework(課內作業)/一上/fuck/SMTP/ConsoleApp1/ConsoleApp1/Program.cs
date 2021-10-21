using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net.Mail;  //記得要加這個命名空間

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            System.Net.Mail.SmtpClient my_mail = new System.Net.Mail.SmtpClient("smtp.gmail.com", 587);

            //建立 SmtpClient 物件 並設定 Gmail的smtp主機及Port，如果用gmail 這邊直接用預設，不用修改

            //Port 587 - SMTP Submission
            //要修改安全性設定 https://www.google.com/settings/security/lesssecureapps

            my_mail.Credentials = new System.Net.NetworkCredential("koyoyo168@gmail.com" ,"sgxoxds1031");//輸入自己的gmail信箱和密碼

            my_mail.EnableSsl = true;//Gmial 的 smtp 使用 SSL，直接用預設，不用修改

            my_mail.Send("koyoyo168@gmail.com", "koyoyo168@gmail.com", "like this", "就像醬!");//發送Email    
        }
    }
}
