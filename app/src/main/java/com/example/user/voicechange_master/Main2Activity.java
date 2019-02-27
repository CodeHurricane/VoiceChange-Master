package com.example.user.voicechange_master;

import android.app.Activity;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

import org.fmod.FMOD;

import java.io.File;

public class Main2Activity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        org.fmod.FMOD.init(this);

    }


    public void play(View view){
        String path = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separatorChar + "drumloop.wav";
      int mode=0;
       playSounr(path,mode);
    }
    @Override
    protected void onDestroy() {
        FMOD.close();
        super.onDestroy();
    }
    static
    {
        System.loadLibrary("native-lib");
    }
    private native void  playSounr(String path, int type);
}
