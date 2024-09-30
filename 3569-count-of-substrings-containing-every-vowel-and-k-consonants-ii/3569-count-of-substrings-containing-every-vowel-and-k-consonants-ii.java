import java.util.*;

class Solution {

    public long countOfSubstrings(String word, int k) {
        return countAtLeastMConsonants(word, k) - countAtLeastMConsonants(word, k + 1);
    }

    private long countAtLeastMConsonants(String word, int m) {
        int n = word.length();
        int numConsonants = 0, l = 0, r = 0;
        long ans = 0;
        Map<Character, Integer> vowelsMap = new HashMap<>();
        Set<Character> vowels = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u'));

        while (r < n || l < n) {
            // When we have all 5 vowels and at least m consonants
            if (vowelsMap.size() == 5 && numConsonants >= m) {
                ans += n - r + 1;  // Counting substrings
                if (!vowels.contains(word.charAt(l))) {
                    numConsonants--;
                } else {
                    char leftChar = word.charAt(l);
                    vowelsMap.put(leftChar, vowelsMap.get(leftChar) - 1);
                    if (vowelsMap.get(leftChar) == 0) {
                        vowelsMap.remove(leftChar);
                    }
                }
                l++;  // Move the left pointer
            } else {
                if (r == n) break;  // If right pointer reaches the end, stop
                char rightChar = word.charAt(r);
                if (!vowels.contains(rightChar)) {
                    numConsonants++;
                } else {
                    vowelsMap.put(rightChar, vowelsMap.getOrDefault(rightChar, 0) + 1);
                }
                r++;  // Move the right pointer
            }
        }
        return ans;
    }
}
