n = gets().to_i

countries = Hash.new

(0...n).each do |i|
	country = gets(sep=" ")
	name = gets(sep=" ")
	name = gets()
	if countries.has_key? country then
		countries[country] += 1
	else
		countries[country] = 1
	end
end

countries = countries.sort

countries.each do |key, value|
	print (key + " " + value.to_s + "\n")
end