use std::collections::HashMap;
impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() { return false;}
        let mut fr = HashMap::new();
        for c in s.chars() {
            *fr.entry(c).or_insert(0) += 1;
        }
        for c in t.chars() {
            *fr.entry(c).or_insert(0) -= 1;
        }
        for v in fr.values() {
            if *v != 0 {
                return false;
            }
        }
        true
    }
}
