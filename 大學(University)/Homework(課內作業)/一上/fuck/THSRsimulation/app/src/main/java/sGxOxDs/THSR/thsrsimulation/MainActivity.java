package sGxOxDs.THSR.thsrsimulation;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.Button;
import android.widget.TextView;

import java.text.DecimalFormat;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,WindowManager.LayoutParams.FLAG_FULLSCREEN);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        setContentView(R.layout.activity_main);
        Button button_thsr_time = (Button) findViewById(R.id.button_THSR_time);
        button_thsr_time.setOnClickListener(THSRtime);

        /*WebView wv = findViewById(R.id.web_WV);
        wv.getSettings().setJavaScriptEnabled(true);
        wv.setWebViewClient(new WebViewClient());*/

    }
    int btncount=0;
    boolean THSR_time=false,Web_CL_Bool=false;

    public void ordersimulationbtn(View view){
        Intent intent = new Intent();
        intent.setClass(MainActivity.this,Order_Simulation.class);
        startActivity(intent);
    }
    public void timewebbtn(View view){
        Intent intent = new Intent();
        intent.setClass(MainActivity.this,WEB_time.class);
        startActivity(intent);
    }
    public void orderwebbtn(View view){
        Intent intent = new Intent();
        intent.setClass(MainActivity.this,WEB_order.class);
        startActivity(intent);
    }

    public void next(View view){
        TextView result = (TextView)findViewById(R.id.Result);
        if(btncount==0) {
            result.setText( getText(R.string.data1));
            btncount++;
        }
        else if(btncount==1) {
            result.setText( getText(R.string.data2));
            btncount++;
        }
        else if(btncount==2) {
            result.setText( getText(R.string.data3));
            btncount-=2;
        }
    }
    public void previous(View view) {
        TextView result = (TextView)findViewById(R.id.Result);
        if(btncount==0) {
            result.setText( getText(R.string.data1));
            btncount+=2;
        }
        else if(btncount==1) {
            result.setText( getText(R.string.data2));
            btncount--;
        }
        else if(btncount==2) {
            result.setText( getText(R.string.data3));
            btncount--;
        }
    }

    private final View.OnClickListener THSRtime = new View.OnClickListener() {
        @Override
        public void onClick(View v) {
            //DecimalFormat str = new DecimalFormat("0");
            //int hr = 13, min = 10, sec = 55;
            //result.setText(str.format(hr) + getText(R.string.hr) + str.format(min) + getText(R.string.min) + str.format(sec) + getText(R.string.sec));
            TextView result = (TextView)findViewById(R.id.Result);
            if(!(THSR_time)){
                result.setText( getText(R.string.data1));
                btncount=0;
                THSR_time=true;
                findViewById(R.id.button_next).setVisibility(View.VISIBLE);
                findViewById(R.id.button_previous).setVisibility(View.VISIBLE);
            }
            else if(THSR_time){
                THSR_time=false;
                findViewById(R.id.button_next).setVisibility(View.GONE);
                findViewById(R.id.button_previous).setVisibility(View.GONE);
                result.setText( getText(R.string.qq));
            }
        }
    };

}
