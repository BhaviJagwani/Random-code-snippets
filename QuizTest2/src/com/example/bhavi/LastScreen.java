package com.example.bhavi;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class LastScreen extends Activity {
	
		TextView tv;
		Button yes;
		Button no;
	 @Override
	    public void onCreate(Bundle savedInstanceState) {
	        super.onCreate(savedInstanceState);
	        setContentView(R.layout.lstscrn);
	        int score;
	        boolean flag;
	        score=getIntent().getExtras().getInt("score");
	        flag=getIntent().getExtras().getBoolean("flag");
	        tv=(TextView)findViewById(R.id.textview1);
	        if(flag)
	        	tv.setText("You win !!! \nYour Score : "+ score);
	        else tv.setText("Your Score : "+ score);
	        yes=(Button)findViewById(R.id.yes);
	        no=(Button)findViewById(R.id.no);
	        yes.setText("Try Again!");
	        no.setText("No,Thanks!");
	        yes.setOnClickListener(new OnClickListener(){
	        	@Override
				public void onClick(View arg0) {
	        	Intent mainInt=new Intent();
	        	mainInt.setClass(getBaseContext(),QuizTest2Activity.class);
	        	startActivity(mainInt);
	        	finish();
	        	
	        	}	
	        });
	        
	        no.setOnClickListener(new OnClickListener(){
	        	@Override
				public void onClick(View arg0) {
	        	Toast.makeText(getBaseContext(),"Thank you for playing!",Toast.LENGTH_SHORT).show();
	        	finish();
	        	
	        	}
	        	
	        });
	 }
}
