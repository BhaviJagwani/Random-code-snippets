package com.example.bhavi;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.TextView;

public class QuizTest2Activity extends Activity {
    /** Called when the activity is first created. */
	RadioButton chc1;
	RadioButton chc2;
	RadioButton chc3;
	RadioButton chc4;
	Button okay;
	InputStream instream1,instream2,instream3;
	BufferedReader br1,br2,br3;
	String str="";
	TextView tv;
	int count=0;
	boolean over=false;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        chc1=(RadioButton)findViewById(R.id.opt1);
        chc2=(RadioButton)findViewById(R.id.opt2);
        chc3=(RadioButton)findViewById(R.id.opt3);
        chc4=(RadioButton)findViewById(R.id.opt4);
        
        okay=(Button)findViewById(R.id.Submit);
        
        tv=(TextView)findViewById(R.id.textview);
        
        try{
        	
        instream1=this.getResources().openRawResource(R.drawable.ques);
        br1=new BufferedReader(new InputStreamReader(instream1));
        instream2=this.getResources().openRawResource(R.drawable.opts);
        br2=new BufferedReader(new InputStreamReader(instream2));
        instream3=this.getResources().openRawResource(R.drawable.ans);
        br3=new BufferedReader(new InputStreamReader(instream3));
        
        str=br1.readLine();
        
        tv.setText(str);
        
        setOpts();
        
        }
        catch(Exception e)
        {
        Log.e(getString(R.string.app_name),e.getMessage());
        }
       
        okay.setOnClickListener(new OnClickListener(){
        
			@Override
			public void onClick(View arg0) {
				try{
					boolean flag=true;
					char ans=(br3.readLine()).charAt(0);
					switch(ans)
					{
					case 'a':if(chc1.isChecked())
								count++;
							 else flag=false;
								break;
					case 'b':if(chc2.isChecked())
								count++;
							 else flag=false; 
								break;
					case 'c':if(chc3.isChecked())
								count++;
					 		 else flag=false; 
								break;
					case 'd':if(chc4.isChecked())
								count++;
					 		else flag=false; 
								break;
					}
				str=br1.readLine();
				if(str!=null&&flag)
				{
					
				tv.setText(str);
				setOpts();
				}
				else {
					Intent intent=new Intent();
					intent.setClass(getBaseContext(), LastScreen.class);
					intent.putExtra("score",count);
					intent.putExtra("flag", flag);
					startActivity(intent);
					finish();	
				}
				}
				
			catch(Exception e){
				Log.e(getString(R.string.app_name),e.getMessage());
			}
			}
			});
        
    }
   
    public void setOpts()
    {	try{
    	 chc1.setText(br2.readLine());
         chc2.setText(br2.readLine());
         chc3.setText(br2.readLine());
         chc4.setText(br2.readLine());
    }
    catch(Exception e){
    Log.e(getString(R.string.app_name),e.getMessage());
    }
    }
}