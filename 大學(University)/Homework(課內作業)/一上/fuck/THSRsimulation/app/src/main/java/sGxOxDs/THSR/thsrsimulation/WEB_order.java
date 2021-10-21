package sGxOxDs.THSR.thsrsimulation;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.webkit.WebView;
import android.webkit.WebViewClient;

public class WEB_order extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_web_order);
        final WebView WO = findViewById(R.id.Order_web);
        WO.getSettings().setJavaScriptEnabled(true);
        WO.setWebViewClient(new WebViewClient());
        WO.loadUrl("https://irs.thsrc.com.tw/IMINT/");
        findViewById(R.id.back).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                WO.goBack();
            }
        });
        findViewById(R.id.home).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent();
                intent.setClass(WEB_order.this,MainActivity.class);
                startActivity(intent);
            }
        });
        findViewById(R.id.time).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent();
                intent.setClass(WEB_order.this,WEB_time.class);
                startActivity(intent);
            }
        });
    }
}
