package sGxOxDs.THSR.thsrsimulation;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

public class Order_Simulation extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_order__simulation);
        findViewById(R.id.home).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent();
                intent.setClass(Order_Simulation.this,MainActivity.class);
                startActivity(intent);
            }
        });
        final Spinner spinner_time = findViewById(R.id.train_order_time);
        String train[] = {"13時12分 3489",
                "13時45分 1089",
                "14時15分 1879",
                "14時55分 255",
                "15時25分 749",
                "15時40分 1354",
                "16時05分 948",
                "16時43分 460",
                "17時16分 681",
                "17時44分 1654",
                "18時18分 3349",
                "18時39分 359"};
        ArrayAdapter<String> trainList = new ArrayAdapter<>(Order_Simulation.this,
                android.R.layout.simple_spinner_dropdown_item,
                train);
        spinner_time.setAdapter(trainList);

        final Spinner spinner_start = findViewById(R.id.spinner_start);
        final String start[] = {"南港",
                "台北",
                "板橋",
                "桃園",
                "新竹",
                "苗栗",
                "台中",
                "彰化",
                "雲林",
                "嘉義",
                "台南",
                "左營"};
        ArrayAdapter<String> startList = new ArrayAdapter<>(Order_Simulation.this,
                android.R.layout.simple_spinner_dropdown_item,
                start);
        spinner_start.setAdapter(startList);

        final Spinner spinner_end = findViewById(R.id.spinner_end);
        String end[] = {"南港",
                "台北",
                "板橋",
                "桃園",
                "新竹",
                "苗栗",
                "台中",
                "彰化",
                "雲林",
                "嘉義",
                "台南",
                "左營"};
        ArrayAdapter<String> endList = new ArrayAdapter<>(Order_Simulation.this,
                android.R.layout.simple_spinner_dropdown_item,
                end);
        spinner_end.setAdapter(endList);

        final Spinner spinner_seat = findViewById(R.id.spinner_seat);
        String seat[] = {"無",
                "靠窗",
                "走道"};
        ArrayAdapter<String> seatList = new ArrayAdapter<>(Order_Simulation.this,
                android.R.layout.simple_spinner_dropdown_item,
                seat);
        spinner_seat.setAdapter(seatList);

        final Spinner spinner_type = findViewById(R.id.spinner_type);
        String type[] = {"全票",
                "半票",
                "愛心票",
                "敬老票"};
        ArrayAdapter<String> typeList = new ArrayAdapter<>(Order_Simulation.this,
                android.R.layout.simple_spinner_dropdown_item,
                type);
        spinner_type .setAdapter(typeList);

        final Spinner spinner_count = findViewById(R.id.spinner_count);
        String count[] = {"1",
                "2",
                "3",
                "4",
                "5"};
        ArrayAdapter<String> countList = new ArrayAdapter<>(Order_Simulation.this,
                android.R.layout.simple_spinner_dropdown_item,
                count);
        spinner_count.setAdapter(countList);

        findViewById(R.id.Sorder).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int time = spinner_time.getSelectedItemPosition();
                int strat = spinner_start.getSelectedItemPosition();
                int end = spinner_end.getSelectedItemPosition();
                int type = spinner_type.getSelectedItemPosition();
                int seat = spinner_seat.getSelectedItemPosition();
                int count = spinner_count.getSelectedItemPosition();
                // |start-end| *140$ *12min *count *type
                spinner_time.setVisibility(View.GONE);
                spinner_start.setVisibility(View.GONE);
                spinner_end.setVisibility(View.GONE);
                spinner_type.setVisibility(View.GONE);
                spinner_seat.setVisibility(View.GONE);
                spinner_count.setVisibility(View.GONE);

                TextView TV = findViewById(R.id.TV_order);
                TextView PT = findViewById(R.id.ptime);
                TextView PM = findViewById(R.id.pmoney);

                TV.setText(getText(R.string.After_order));

                int tempi = 0;
                String temps;
                if(strat>end) { tempi = strat-end; }
                else if(strat<end) { tempi = end-strat; }
                tempi = tempi*12;
                temps = String.valueOf(tempi);
                PT.setText( temps+"mins " );
                if(type == 0) { tempi = tempi/12*140; }
                else { tempi = tempi/12*70; }
                temps = String.valueOf(tempi);
                PM.setText(temps+"NTD ");
                final String temps1=temps;

                PT.setVisibility(View.VISIBLE);
                PM.setVisibility(View.VISIBLE);

                findViewById(R.id.imageView).setVisibility(View.GONE);
                findViewById(R.id.imageView1).setVisibility(View.GONE);
                findViewById(R.id.imageView2).setVisibility(View.GONE);
                findViewById(R.id.imageView3).setVisibility(View.GONE);
                findViewById(R.id.imageView4).setVisibility(View.GONE);
                findViewById(R.id.imageView5).setVisibility(View.GONE);

                findViewById(R.id.linepay).setVisibility(View.VISIBLE);
                findViewById(R.id.linepay).setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        Toast.makeText(Order_Simulation.this,"成功支付"+temps1+"NTD ",Toast.LENGTH_LONG).show();
                        Intent intent = new Intent();
                        intent.setClass(Order_Simulation.this,paydone.class);
                        startActivity(intent);
                    }
                });

            }
        });
    }
}
