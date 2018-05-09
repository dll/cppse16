package cn.edu.chzu.xxxy.sp15.ldl.accountms;

import java.text.SimpleDateFormat;
import java.util.Date;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;


public class MainActivity extends Activity {
	final String TAG = "***��������***"; 
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Log.v(TAG, "onCreate");
    }
  //�����������ڿ�ʼʱ�����ã����û�������б�Ҫ�ĸ���
  	@Override
  	protected void onStart() {
  		super.onStart();
  		Log.d(TAG, "onStart()");
  	}

  	//��������ڿ�ʼʱ�����ã��ָ���onPause()ֹͣ���û�������µ���Դ
  	@Override
  	protected void onResume() {
  		super.onResume();
  		Log.i(TAG, "onResume()");
  		SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		Log.i("INFO", "�û���[ " + df.format(new Date()) + " ]��¼��"); // �������Info��־��Ϣ
  	}
  	//�����½����������ǰ�����ã������������ĸ�����Ϣ
  	@Override
  	protected void onRestart() {
  		super.onRestart();
  		Log.w(TAG, "onRestart()");
  	}
  	//�ڻ�������ڽ���ʱ�����ã���������־õ����ݻ��ͷ�ռ�õ���Դ
  	@Override
  	protected void onPause() {
  		super.onPause();
  		Log.e(TAG, "onPause()");
  	}
  	//�ڿ����������ڽ���ʱ�����ã������ͷ�ռ�õ���Դ
  	@Override
  	protected void onStop() {
  		super.onStop();
  		Log.i(TAG, "onStop()");
  	}
  	//�������������ڽ���ʱ�����ã��ͷ���Դ
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
