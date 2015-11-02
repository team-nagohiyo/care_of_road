/****************************************************************************
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2011      Zynga Inc.
Copyright (c) 2013-2014 Chukong Technologies Inc.
 
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package org.cocos2dx.cpp;

import org.cocos2dx.lib.Cocos2dxActivity;
import android.os.Bundle;

import com.unity3d.ads.android.IUnityAdsListener;
import com.unity3d.ads.android.UnityAds;

public class AppActivity extends Cocos2dxActivity
implements IUnityAdsListener
{
	@Override
	protected void onCreate(final Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        UnityAds.setDebugMode(true);
        UnityAds.setTestMode(true);
        UnityAds.init(this, "1008934", this);
	}
	
	@Override
	public void onResume() {
	  super.onResume();
	  //アクティビティが変更された時は登録しなおす。
	  //UnityAds.changeActivity(this);
	}
	
	@Override
	/**
	 * 動画在庫がある場合のイベント
	 */
	public void onFetchCompleted() {
	}

	@Override
	/**
	 * 動画在庫がない場合のイベント
	 */
	public void onFetchFailed() {
	}

	@Override
	/**
	 * UnityAdsが表示されたイベント
	 */
	public void onHide() {
	}

	@Override
	/**
	 * UnityAdsが閉じられたイベント
	 */
	public void onShow() {
	}

	@Override
	/**
	 * 動画の再生開始イベント
	 */
	public void onVideoStarted() {
	}
	
	@Override
	/**
	 * 動画の再生完了イベント
	 * @param key インセンティブキー
	 * @param skip スキップしたか
	 */
	public void onVideoCompleted(String key, boolean skip) {
	}

	/**
	 * UnityAdsの広告表示準備が完了しているか
	 * @return 表示可能
	 */
	public static boolean canUnityAdsShow()
	{
		return UnityAds.canShow() && UnityAds.canShowAds() && UnityAds.isSupported();
	}

	/**
	 * UnityAdsの広告を表示する
	 */
	public static void showUnityAds()
	{
		  UnityAds.show();
	}
}
