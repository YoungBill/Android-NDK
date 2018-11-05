package baina.android.com.hellondk;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());

        findViewById(R.id.callShowBt).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                new Test(MainActivity.this).callShow("这个是调用Test类里面的show");
            }
        });

        findViewById(R.id.callToastShowBt).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                new Test().callToastShow(MainActivity.this, "这个是JNI直接调用Toast");
            }
        });
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
}
