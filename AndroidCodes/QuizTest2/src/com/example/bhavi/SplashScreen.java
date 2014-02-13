package com.example.bhavi;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

public class SplashScreen extends Activity {
	 
		protected int splashTime=2000;
		protected boolean active=true;
		TextView tv;
		
	 @Override
	    public void onCreate(Bundle savedInstanceState) {
		 super.onCreate(savedInstanceState);
		 setContentView(R.layout.splash);
		 tv=(TextView)findViewById(R.id.welcome);
		 tv.setText("Welcome to the Quiz !");
		 Thread splashTread = new Thread() {
		        @Override
		        public void run() {
		            try {
		                int waited = 0;
		                while(active&&waited < splashTime) {
		                    sleep(100);
		                    if(active)
		                    waited += 100;
		                }
		            } catch(InterruptedException e) {
		                // do nothing
		            } finally {
		            	 finish();
		                Intent splashI=new Intent();
		                splashI.setClass(getApplicationContext(), QuizTest2Activity.class);
		                startActivity(splashI);
		               
		                stop();
		            }
		        }
		    };
		    splashTread.start();
		 
	 }

}
