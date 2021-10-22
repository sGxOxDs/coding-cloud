package sGxOxDs.THSR.thsrsimulation;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.webkit.WebView;
import android.webkit.WebViewClient;

public class WEB_time extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_web_time);
        final WebView WT = findViewById(R.id.Time_web);
        WT.getSettings().setJavaScriptEnabled(true);
        WT.setWebViewClient(new WebViewClient());
        WT.loadUrl("https://m.thsrc.com.tw/tw/TimeTable/SearchResult");
        findViewById(R.id.back).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                WT.goBack();
            }
        });
        findViewById(R.id.home).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent();
                intent.setClass(WEB_time.this,MainActivity.class);
                startActivity(intent);
            }
        });
        findViewById(R.id.order).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent();
                intent.setClass(WEB_time.this,WEB_order.class);
                startActivity(intent);
            }
        });
    }
    //https://irs.thsrc.com.tw/IMINT/
}
