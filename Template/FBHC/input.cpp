vector<int> read_seq(int N, int K) {
    vector<int> a(N);
    for(int i = 0; i < K; ++i) {
        cin >> a[i];
    }
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    for(int i = K; i < N; ++i) {
        a[i] = (((ll) A * a[i-2]+ (ll) B * a[i-1] + C) % D) + 1;
    }
    return a;
}
