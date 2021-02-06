package com.myalgorithm.tab;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import java.util.Arrays;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    static String TAG = MainActivity.class.getSimpleName();
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        findViewById(R.id.btn_run).setOnClickListener(this);
        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);

        bindLogPipe();
//        writeMessage("test");
//        //Log.i("TAG", "onCreate: "+readMessage());
//        tv.setText(readMessage());

        new Thread(new Runnable() {
            @Override
            public void run() {
                String result = "<applications>"
                        +"<versions__delta>1</versions__delta>"
                        +"<apps__hashcode></apps__hashcode>"
                        +"</applications>"+"<applications>"
                        +"<versions__delta>1</versions__delta>"
                        +"<apps__hashcode></apps__hashcode>"
                        +"</applications>"+"<applications>"
                        +"<versions__delta>1</versions__delta>"
                        +"<apps__hashcode></apps__hashcode>"
                        +"</applications>"+"<applications>"
                        +"<versions__delta>1</versions__delta>"
                        +"<apps__hashcode></apps__hashcode>"
                        +"</applications>"+"<applications>"
                        +"<versions__delta>1</versions__delta>"
                        +"<apps__hashcode></apps__hashcode>"
                        +"</applications>"+"<applications>"
                        +"<versions__delta>1</versions__delta>"
                        +"<apps__hashcode></apps__hashcode>"
                        +"</applications>"+"<applications>"
                        +"<versions__delta>1</versions__delta>"
                        +"<apps__hashcode></apps__hashcode>"
                        +"</applications>"+"<applications>"
                        +"<versions__delta>1</versions__delta>"
                        +"<apps__hashcode></apps__hashcode>"
                        +"</applications>"+"<applications>"
                        +"<versions__delta>1</versions__delta>"
                        +"<apps__hashcode></apps__hashcode>"
                        +"</applications>"+"<applications>"
                        +"<versions__delta>1</versions__delta>"
                        +"<apps__hashcode></apps__hashcode>"
                        +"</applications>"+"<applications>"
                        +"<versions__delta>1</versions__delta>"
                        +"<apps__hashcode></apps__hashcode>"
                        +"</applications>"+"<applications>"
                        +"<versions__delta>1</versions__delta>"
                        +"<apps__hashcode></apps__hashcode>"
                        +"</applications>"+"<applications>"
                        +"<versions__delta>1</versions__delta>"
                        +"<apps__hashcode></apps__hashcode>"
                        +"</applications>"+"<applications>"
                        +"<versions__delta>1</versions__delta>"
                        +"<apps__hashcode></apps__hashcode>"
                        +"</applications>"+"<applications>"
                        +"<versions__delta>1</versions__delta>"
                        +"<apps__hashcode></apps__hashcode>"
                        +"</applications>"+"<applications>"
                        +"<versions__delta>1</versions__delta>"
                        +"<apps__hashcode></apps__hashcode>"
                        +"</applications>"+"<applications>"
                        +"<versions__delta>1</versions__delta>"
                        +"<apps__hashcode></apps__hashcode>"
                        +"</applications>"+"<applications>"
                        +"<versions__delta>1</versions__delta>"
                        +"<apps__hashcode></apps__hashcode>"
                        +"</applications>"+"<applications>"
                        +"<versions__delta>1</versions__delta>"
                        +"<apps__hashcode></apps__hashcode>"
                        +"</applications>"+"<applications>"
                        +"<versions__delta>1</versions__delta>"
                        +"<apps__hashcode></apps__hashcode>"
                        +"</applications>";
                byte[] buffer = new byte[8*1024];
                byte[] buffer1 = new byte[8*1024];

                StringBuffer stringBuffer = new StringBuffer();
                long start = System.currentTimeMillis();
                for (int i = 0; i < 1000; i++) {
                    stringBuffer.append(new String(buffer));
                }
                long end = System.currentTimeMillis();
                Log.i("TAG", "run: "+stringBuffer.length()+","+(end-start));
            }
        }).start();

        findViewById(R.id.btn_run).performClick();
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()){
            case R.id.btn_run:
                stringFromJNI();
                //testPipeSize();
                break;
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();

        unbindLogPipe();
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native void unbindLogPipe();
    public native int bindLogPipe();
    public native String readMessage();
    public native int writeMessage(String msg);
    public native int testPipeSize();
}
