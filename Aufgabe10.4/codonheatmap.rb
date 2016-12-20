#!/usr/bin/env ruby
#
# Bocher Diedrich Sandmeier

require './fastaIterator.rb'

class Heatmap

  def initialize(dataset_name, distribution, columns)

    @columns = columns

    @keysorted = distribution.sort_by{|k, v| k}
    @valuesorted = distribution.sort_by{|k, v| v}
    @no_colorgrades = @keysorted.length

    puts '\documentclass{beamer} % start of preamble'
    puts '\usepackage{xcolor,colortbl}'
    puts '\begin{document} % end of preamble'
    puts '\colorlet{color min hsb}[hsb]{red}'
    puts '\colorlet{color max hsb}[hsb]{magenta}'

    puts "\\begin{frame}{Distribution of codons in #{dataset_name}} % header of the slide"

    0.upto(@no_colorgrades - 1) { |i|

      factor = i.to_f * 100 / (@no_colorgrades - 1)
      puts "\\colorlet{color hsb#{i}}{color max hsb!#{factor.round(2)}!color min hsb}"
    }

    puts '\begin{center}'
    puts '\begin{tabular}{*{4}{c}}'

    # here comes the table contents, row by row separated by \\
    # and with column values separated by &
   @keysorted.each_index { |i|
     colorindex = 0
     @valuesorted.each_index { |j|
       if @valuesorted[j][0] == @keysorted[i][0]
         colorindex = j
       end
     }
     print "\\cellcolor{color hsb#{colorindex}}\\texttt{#{@keysorted[i][0]}}{\\tiny #{@keysorted[i][1]}}"

     if ((i % @columns) == (@columns - 1) || i == @keysorted.length - 1)
       puts '\\\\' # needs to be escaped, because concatenated in line with the print command above?
     else
       print '&'
     end
   }

    puts '\end{tabular}'
    puts '\end{center}'
    puts '\end{frame} % end of this slide'
    puts '\end{document}'

  end

end

#

def get_sequence(filename)
  sequence_string = ''
  fi = FastaIterator.new(filename)
  fi.each() {|header,seq|
    sequence_string = seq
  }
  return sequence_string
end

def get_orf_distribution(sequence)

  distribution = {}

  # non-greedy match, write that into list, then continue matching
  # from last starting position +3 until the end
  while match = sequence.match(/([ATGC]{3})/)
    index = match[0]
    if !distribution.has_key?(index)
      distribution[index] = 0
    end

    distribution[index] += 1

    sequence = sequence.slice(match.begin(0)+3..-1)
  end

  return distribution
end

##########

no_columns = 4

if ARGV.length != 1
  STDERR.puts "Usage: #{$0} Filename"
  exit 1
end

filename = ARGV[0]

sequence_string = get_sequence(filename)

distribution = get_orf_distribution(sequence_string)

heatmap = Heatmap.new(filename, distribution, no_columns)
