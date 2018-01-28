


# **Hexxcoin [HXX] swap 2017**

Anonymous Zerocoin Protocol:
https://en.wikipedia.org/wiki/Zerocoin

Zerocoin  parameters RSA-2048 from RSA Factoring Challenge
https://en.wikipedia.org/wiki/RSA_Factoring_Challenge

Hexxcoin
----------------
* Coin Suffix: HXX
* Algorithm:lyra2z330
* Algo params: LYRA2(BEGIN(thash), 32, BEGIN(nVersion), 80, BEGIN(nVersion), 80, 2, 330, 256)
* Target Spacing: 150 Seconds
* Retarget: every block
* Confirmation: 6 Blocks
* Maturity: 120 Blocks
* Blocks: ~576 per day
* Total Coins: 9,999,999 HXX
* Min TX Fee: 0.001 HXX
* Block Size: 4MB

Reward table
----------------
* 2 weeks / 1 coin
* 1 week / 3.125 coins
* 1 week / 6.25 coins
* 2 weeks / 12.5 coins
* 6 weeks / 6.25 coins
* 6 weeks / 3.125 coins
* 6 weeks / 1.5625 coins
* And finally, 1 coin reward / block


Net Parameters
----------------
* P2P Port=29100
* RPC Port=29200
* Client core=0.8.7
* Client name=hexxcoin.exe
* Conf file=hexxcoin.conf

Installation folder
----------------
* Windows: C:\Users\Username\AppData\Roaming\hexxcoin
* Mac:/Library/Application Support/hexxcoin
* Unix: /.hexxcoin




Debian/Ubuntu Linux Daemon Build Instructions
================================================

install dependencies:

    $ sudo apt-get update && sudo apt-get upgrade
    $ sudo apt-get install git build-essential libssl-dev libdb5.3++-dev libminiupnpc-dev libboost-all-dev

build hexxcoind from git:

    $ git clone https://github.com/hexxcointakeover/hexxcoin
    $ cd hexxcoin/src && make -f makefile.unix
   
install and run hexxcoind daemon:

    $ sudo strip hexxcoind && sudo cp ~/hexxcoin/src/hexxcoind /usr/bin && cd ~/
    $ hexxcoind

here are a few commands, google for more.

    $ ./hexxcoind getinfo
    $ ./hexxcoind getpeerinfo
    $ ./hexxcoind getmininginfo
    $ ./hexxcoind getnewaddresss
	
	
if you need a swap memory

    $ free
    $ dd if=/dev/zero of=/var/swap.img bs=1024k count=1000
    $ mkswap /var/swap.img
    $ swapon /var/swap.img	
    $ free	
	
	

Debian/Ubuntu Linux Qt4 Wallet Build Instructions
================================================

update and install dependencies:

    $ sudo apt-get update && sudo apt-get upgrade
    $ sudo apt-get install git build-essential libssl-dev libdb5.3++-dev libminiupnpc-dev libboost-all-dev qt4-qmake libqt4-dev
build Hexxcoin-qt from git:

    $ git clone https://github.com/hexxcointakeover/hexxcoin
    $ cd hexxcoin && qmake -qt=qt4 Hexxcoin-qt.pro && make
 
running the hexxcoin Qt wallet:

    $ sudo ./hexxcoin
 
 Debian/Ubuntu Linux Qt5 Wallet Build Instructions
================================================

update and install dependencies:

    $ sudo apt-get update && sudo apt-get upgrade
    $ sudo apt-get install git build-essential libssl-dev libdb5.3++-dev libminiupnpc-dev libboost-all-dev qt5-qmake libqt5gui5 libqt5core5 libqt5dbus5 qttools5-dev-tools
build Hexxcoin-qt from git:

    $ git clone https://github.com/hexxcointakeover/hexxcoin
    $ cd hexxcoin && qmake -qt=qt5 Hexxcoin-qt.pro && make
 
running the hexxcoin Qt wallet:

    $ sudo ./hexxcoin

Example hexxcoin.conf Configuration
===================================================

	addnode=node_ip
	rpcallowip=127.0.0.1
	rpcuser=MAKEUPYOUROWNUSERNAME
	rpcpassword=MAKEUPYOUROWNPASSWORD
	rpcport=29100
	server=1
	listen=1
	port=29200
	
	



