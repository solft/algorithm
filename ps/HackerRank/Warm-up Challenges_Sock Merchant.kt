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

// Sock Merchant
// 단순 구현 문제
// 양말 종류 배열이 주어지면
// 짝 맞는 양말이 총 몇 개 나오는지 구하는 문제
fun sockMerchant(n: Int, ar: Array<Int>): Int {
    val socks = IntArray(101)
    for (s in ar) {
        socks[s]++
    } 
    var ans = 0
    for (sock in socks){
        ans += (sock / 2)
    }
    return ans
}

fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)

    val n = scan.nextLine().trim().toInt()

    val ar = scan.nextLine().split(" ").map{ it.trim().toInt() }.toTypedArray()

    val result = sockMerchant(n, ar)

    println(result)
}
