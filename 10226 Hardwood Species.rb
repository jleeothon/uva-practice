begin

T = gets.to_i

(0...T).each do |t|
	trees = Hash.new
	total
	while true
		tree = gets
		if trees.has_key? tree then
			trees[tree] = 1
		else
			trees[tree] += 1
		end
		total += 1
	end
	trees = trees.sort
	trees.each_pair do |treename, number|
		print treename + " " + (number/total).round(4).to_s
	end
end

rescue

end