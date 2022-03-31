build:
	g++ main.cpp rezolvari.cpp player.cpp team.cpp Lista.cpp Coada.cpp Arbore.cpp Node.cpp -o lanParty
run:
	./lanParty c.in d.in r.out
clean:
	rm -f lanParty
