class Integer
  def prime_factors
    if self < 2
      raise Math::DomainError.new "numbers < 2 does not have prime factors"
    end
    ans = []
    n, d = self, 2
    until n == 1
      while n % d == 0 
        ans << d
        n /= d
      end
      d = d.next_prime
    end
    ans
  end

  def next_prime
    candidate = self + 1
    until candidate.is_prime
      candidate += 1
    end
    candidate
  end
      
  def is_prime
    if self < 2
      false
    else
      (2..Math.sqrt(self).floor).map { |d| self % d != 0 }.all?
    end
  end
end 

