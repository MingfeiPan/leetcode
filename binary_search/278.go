/** 
 * Forward declaration of isBadVersion API.
 * @param   version   your guess about first bad version
 * @return 	 	      true if current version is bad 
 *			          false if current version is good
 * func isBadVersion(version int) bool;
 */

func firstBadVersion(n int) int {
    var start, end, mid int
    start = 1
    end = n
    mid = (end - start) / 2 + start
    for start < end {
        mid = (end - start) / 2 + start
        if isBadVersion(mid) {
            // mid是bad 检查前一个如果不是bad可以return mid为第一个bad
            if !isBadVersion(mid-1) {
                return mid
            }
            end = mid
        }else {
            // 如果mid不是bad 检查后一个mid+1 如果是bad return mid+1 为第一个bad
            if isBadVersion(mid+1) {
                return mid+1
            }
            start = mid + 1
        }
    }
    return mid
}
