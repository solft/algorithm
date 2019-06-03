
// 14322 Country Leader (Small)
// 14323 Country Leader (Large)
// 분류: 카운팅
// 문제:
//      이름들 입력 받고 다른 알파벳이 가장 많은 사람을 찾는 문제
//      같을 경우 알파벳순으로 빠른 사람
// 풀이:
//      이름들 입력 받고 정렬한 뒤
//      셋에 알파벳 넣고 사이즈를 구해서 가장 큰 사람을 찾았다.
fun main() {
    val t = readLine()!!.toInt()
    for(i in 1..t){
        val person = readLine()!!.toInt()
        var ans = ""
        var leader = 0

        val nameList = mutableListOf<String>()
        for (j in 1 .. person){
            val name = readLine()!!
            nameList.add(name)

        }
        nameList.sort()
        for(name in nameList){
            val set = mutableSetOf<Char>()

            for(c in name){
                if(c != ' ')
                    set.add(c)
            }
            if (leader < set.size){
                leader = set.size
                ans = name
            }
        }
        println("Case #$i: $ans")
    }
}
