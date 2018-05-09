package cn.edu.chzu.xxxy.sp15.ldl.accountms;

import java.text.SimpleDateFormat;
import java.util.Date;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;


public class MainActivity extends Activity {
	final String TAG = "***生命周期***"; 
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Log.v(TAG, "onCreate");
    }
  //可视生命周期开始时被调用，对用户界面进行必要的更改
  	@Override
  	protected void onStart() {
  		super.onStart();
  		Log.d(TAG, "onStart()");
  	}

  	//活动生命周期开始时被调用，恢复被onPause()停止的用户界面更新的资源
  	@Override
  	protected void onResume() {
  		super.onResume();
  		Log.i(TAG, "onResume()");
  		SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		Log.i("INFO", "用户于[ " + df.format(new Date()) + " ]登录。"); // 输出程序Info日志信息
  	}
  	//在重新进入可视生命前被调用，载入界面所需的更改信息
  	@Override
  	protected void onRestart() {
  		super.onRestart();
  		Log.w(TAG, "onRestart()");
  	}
  	//在活动生命周期结束时被调用，用来保存持久的数据或释放占用的资源
  	@Override
  	protected void onPause() {
  		super.onPause();
  		Log.e(TAG, "onPause()");
  	}
  	//在可视生命周期结束时被调用，用来释放占用的资源
  	@Override
  	protected void onStop() {
  		super.onStop();
  		Log.i(TAG, "onStop()");
  	}
  	//在完整生命周期结束时被调用，释放资源
  	@Override
  	protected void onDestroy() {
  		super.onDestroy();
  		Log.i(TAG, "onDestroy()");
  	}

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
}
