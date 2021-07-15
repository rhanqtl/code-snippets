require "./fact.rb"

def comb n, k
  fact(n) / (fact(k) * fact(n - k))
end
