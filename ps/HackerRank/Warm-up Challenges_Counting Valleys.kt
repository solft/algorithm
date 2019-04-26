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

// Counting Valleys
// 단순 구현 문제
// valley가 몇 개인지 새면 되는 문제
// valley란 해수면 아래로 내려가 해수면 밖으로 올라오는 구간이 valley 1개
fun countingValleys(n: Int, s: String): Int {
    var seaLevel = 0
    var inSea = false
    var ans = 0
    for(i in 0 until n){
        if(s[i] == 'U') {
            seaLevel++
            if(seaLevel >= 0 && inSea) {
                ans++
                inSea = false
            }
        }    
        else if(s[i] == 'D') {
            seaLevel--
            if(seaLevel < 0 && !inSea)
                inSea = true
        }
    }
    return ans
}

fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)

    val n = scan.nextLine().trim().toInt()

    val s = scan.nextLine()

    val result = countingValleys(n, s)

    println(result)
}
