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
import kotlin.math.*

// Jumping on the Clouds
// dp 문제
// dp를 활용해 가장 적게 가게끔 만들어 주었다.
fun jumpingOnClouds(n: Int, c: Array<Int>): Int {
    val dp = IntArray(n)
    dp[0] = 0
    if(c[1] == 0)
        dp[1] = 1
    else
        dp[1] = 1000000000
    for (i in 2 until n){
        if(c[i] == 0)
            dp[i] = min(dp[i-1]+1, dp[i-2]+1)
        else
            dp[i] = 1000000000
    }
    return dp[n-1]
}

fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)

    val n = scan.nextLine().trim().toInt()

    val c = scan.nextLine().split(" ").map{ it.trim().toInt() }.toTypedArray()

    val result = jumpingOnClouds(n, c)

    println(result)
}
