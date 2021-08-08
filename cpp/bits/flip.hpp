namespace hq {
    namespace bits {
        int flip(int ori, int k) {
            return ori ^ (1 << k);
        }
    }
}