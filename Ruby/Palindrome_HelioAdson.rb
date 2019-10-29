print 'String: '
string = gets.chomp

def palindrome? (string)
    if string.downcase.delete(' ') == string.reverse.downcase.delete(' ')
        return true  
    end 
    return false   
end

puts palindrome? string