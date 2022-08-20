package com.ktcode.learn

import android.graphics.Bitmap
import android.graphics.drawable.Drawable
import android.util.SparseArray
import android.view.View
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView

/**
 * kt 内置扩展函数
 * apply
 * let
 * run
 * with
 * also
 */
class KtStd {

    fun let(item: Student){
        val result = item.let {
            println(it.name)
            1000
        }
    }
    fun also(item: Student){
        val result = item.also {
            println(it.name)
            1000
        }
    }

    fun apply(item: Student) {
        item.apply {
            id = 24
        }
    }

    fun convert1(holder: BaseViewHolder, item: Student) {
        with(item) {
            holder.setText(1, id)
            holder.setText(2, name)
            holder.setVisible(3, sex)
            holder.setText(2, intro)
        }
    }

    fun convert2(holder: BaseViewHolder, item: Student) {
        item.run {
            holder.setText(1, id)
            holder.setText(2, name)
            holder.setVisible(3, sex)
            holder.setText(2, intro)
        }
    }
}

fun main() {
    val info: Student = Student(1, "小明", false, "来自昆明")
    val ktStd = KtStd()
/*    ktStd.convert1(BaseViewHolder(null), info)
    ktStd.convert2(BaseViewHolder(null), info)*/

    ktStd.apply(info)
    ktStd.let(info)
    ktStd.also(info)

}

data class Student(
    var id: Int,
    val name: String,
    val sex: Boolean,
    val intro: String
)


/**
 * ViewHolder 基类
 */
open class BaseViewHolder(view: View?) : RecyclerView.ViewHolder(view!!) {
    /**
     * Views indexed with their IDs
     */
    private val views: SparseArray<View> = SparseArray()


    open fun <T : View> getView(viewId: Int): T {
        val view = getViewOrNull<T>(viewId)
        checkNotNull(view) { "No view found with id $viewId" }
        return view
    }

    @Suppress("UNCHECKED_CAST")
    open fun <T : View> getViewOrNull(viewId: Int): T? {
        val view = views.get(viewId)
        if (view == null) {
            itemView.findViewById<T>(viewId)?.let {
                views.put(viewId, it)
                return it
            }
        }
        return view as? T
    }

    open fun <T : View> Int.findView(): T? {
        return itemView.findViewById(this)
    }

    open fun setText(viewId: Int, value: CharSequence?): BaseViewHolder {
        getView<TextView>(viewId).text = value
        return this
    }

    open fun setText(viewId: Int, strId: Int): BaseViewHolder? {
        getView<TextView>(viewId).setText(strId)
        return this
    }

    open fun setTextColor(viewId: Int, color: Int): BaseViewHolder {
        getView<TextView>(viewId).setTextColor(color)
        return this
    }

    open fun setTextColorRes(viewId: Int, colorRes: Int): BaseViewHolder {
        getView<TextView>(viewId).setTextColor(itemView.resources.getColor(colorRes))
        return this
    }

    open fun setImageResource(viewId: Int, imageResId: Int): BaseViewHolder {
        getView<ImageView>(viewId).setImageResource(imageResId)
        return this
    }

    open fun setImageDrawable(viewId: Int, drawable: Drawable?): BaseViewHolder {
        getView<ImageView>(viewId).setImageDrawable(drawable)
        return this
    }

    open fun setImageBitmap(viewId: Int, bitmap: Bitmap?): BaseViewHolder {
        getView<ImageView>(viewId).setImageBitmap(bitmap)
        return this
    }

    open fun setBackgroundColor(viewId: Int, color: Int): BaseViewHolder {
        getView<View>(viewId).setBackgroundColor(color)
        return this
    }

    open fun setBackgroundResource(viewId: Int, backgroundRes: Int): BaseViewHolder {
        getView<View>(viewId).setBackgroundResource(backgroundRes)
        return this
    }

    open fun setVisible(viewId: Int, isVisible: Boolean): BaseViewHolder {
        val view = getView<View>(viewId)
        view.visibility = if (isVisible) View.VISIBLE else View.INVISIBLE
        return this
    }

    open fun setGone(viewId: Int, isGone: Boolean): BaseViewHolder {
        val view = getView<View>(viewId)
        view.visibility = if (isGone) View.GONE else View.VISIBLE
        return this
    }

    open fun setEnabled(viewId: Int, isEnabled: Boolean): BaseViewHolder {
        getView<View>(viewId).isEnabled = isEnabled
        return this
    }


}