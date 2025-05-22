package com.myalgorithm.tab

import android.app.Application
import com.tencent.bugly.crashreport.CrashReport

class NdkApp: Application() {
    override fun onCreate() {
        super.onCreate()

        CrashReport.initCrashReport(this, "5eff404523", false);
    }
}