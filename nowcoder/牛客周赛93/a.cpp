public List<Integer> findSubstring(String s, String[] words) {
    List<Integer> result = new ArrayList<>();
    if (words == null || words.length == 0) return result;
    int wordLength = words[0].length();
    int wordsLength = words.length * wordLength;
    Map<String, Integer> wordsMap = new HashMap<>();
    for (String word : words) {
        int num = wordsMap.getOrDefault(word, 0);
        wordsMap.put(word, num + 1);
    }
    for (int a = 0; a < wordLength; a++) {
        boolean ifFirst = true;
        Map<String, Integer> substringMap = new HashMap<>();
        for (int i = a; i <= s.length() - wordsLength; i = i + wordLength) {
            if (ifFirst) {
                String substring = s.substring(i, i + wordsLength);
                for (int j = 0; j <= substring.length() - wordLength; j = j + wordLength) {
                    String word = substring.substring(j, j + wordLength);
                    int num = substringMap.getOrDefault(word, 0);
                    substringMap.put(word, num + 1);
                }
                ifFirst = false;
            } else {
                String left = s.substring(i - wordLength, i);
                int num = substringMap.getOrDefault(left, 0);
                if (num - 1 == 0) {
                    substringMap.remove(left);
                } else substringMap.put(left, num - 1);
                String right = s.substring(i + wordsLength - wordLength, i + wordsLength);
                substringMap.put(right, substringMap.getOrDefault(right, 0) + 1);
            }
            if (substringMap.equals(wordsMap)) {
                result.add(i);
            }
        }
    }
    return result;
}