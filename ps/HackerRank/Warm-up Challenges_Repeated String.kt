import java.io.*
import java.math.*
import java.security.*
import java.text.*
import java.util.*
import java.util.concurrent.*
import java.util.function.*
import java.util.regex.*
import java.util.stream.*
import kotlin.collections.*
import kotlin.comparisons.*
import kotlin.io.*
import kotlin.jvm.*
import kotlin.jvm.functions.*
import kotlin.jvm.internal.*
import kotlin.ranges.*
import kotlin.sequences.*
import kotlin.text.*

// Repeated String
// 문자열이 무한히 반복 될 때 n번재 까지 'a'가 몇 번 나오는지 카운팅 하는 문제
fun repeatedString(s: String, n: Long): Long {
    val sLength = s.length
    var countA = 0
    for(i in s){
        if(i == 'a')
            countA++
    }
    var ans = (n/sLength)*countA
    val mod = (n%sLength).toInt()
    for(i in 0 until mod){
        if(s[i] == 'a')
            ans++
    }
    return ans
}

fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)

    val s = scan.nextLine()

    val n = scan.nextLine().trim().toLong()

    val result = repeatedString(s, n)

    println(result)
}
