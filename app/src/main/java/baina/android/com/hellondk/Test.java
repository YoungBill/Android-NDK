package baina.android.com.hellondk;

import android.content.Context;
import android.widget.Toast;

/**
 * Created by taochen on 18-11-2.
 */

public class Test {
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-test-lib");
    }

    private Context mContext;

    public Test() {

    }

    public Test(Context mContext) {
        this.mContext = mContext;
    }

    public void show(String msg) {
        Toast.makeText(mContext, msg, Toast.LENGTH_SHORT).show();
    }

    //调用自定义类的方法
    public native void callShow(String msg);

    //调用SDK里面的方法
    public native void callToastShow(Context context, String msg);
}
