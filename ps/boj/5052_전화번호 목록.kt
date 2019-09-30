
// 5052번 전화번호 목록
// 분류: 정렬
// 문제:
//      어느 전화번호가 다른 전화번호의 접두어가 되는지 확인하는 문제
// 풀이:
//      정렬 후 인접한 번호끼리 접두어 관계인지 검사한다.
//      어느 번호가 다른 번호의 접두어라면 항상 앞에 위치한다.
fun main() {
    var t = readLine()!!.toInt()

    while(t-- > 0) {
        val n = readLine()!!.toInt()

        val phoneList = mutableListOf<String>()
        for (i in 0 until n) {
            val phone = readLine()!!
            phoneList.add(phone)
        }

        phoneList.sort()
        var isConsistency = true
        for (i in 0 until n - 1) {
            if (phoneList[i+1].startsWith(phoneList[i])) {
                isConsistency = false
                break
            }
        }

        if (isConsistency) {
            println("YES")
        } else {
            println("NO")
        }
    }
}
