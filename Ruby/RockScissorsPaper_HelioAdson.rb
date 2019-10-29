class RSP
    attr_accessor :Player1 
    attr_accessor :Player2 
    attr_accessor :result
    def Game
        print "Player 1: "
        @Player1 = gets.chomp.downcase.delete(' ')
        print "Player 2: "
        @Player2 = gets.chomp.downcase.delete(' ')
        case @Player1
        when "rock"
            if @Player2 == "paper" 
                @result = "p2 win!" 
            else 
                @result = "p1 win!"
            end 
        when "paper"
            if @Player2 == "scissor" 
                @result = "p2 win!" 
            else 
                @result = "p1 win!"
            end  
        when "scissor"
            if @Player2 == "rock" 
                @result = "p2 win!" 
            else 
                @result = "p1 win!"
            end          
        end
        if @Player1 == @Player2 
            @result = "Draw!"
        end              
    end

    def Result
        puts @result
    end

end    

game =  RSP.new

game.Game
game.Result