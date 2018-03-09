Xnode Instructions and Notes
=============================
 - Version 0.1.7
 - Date: 6 March 2018

Prerequisites
-------------
 - Ubuntu 16.04+
 - Port **29100** is open
 - Libraries to build from hexxcoin source if you want to build it yourself

Step 0. ON VPS: Build (Optional - use latest linux-x64 binaries otherwise)
----------------------
**0.1.**  Check out from source:

    git clone https://github.com/hexxcointakeover/4.0.1.X

**0.2.**  See [README.md](README.md) for instructions on building.


Step 1. ON VPS: Open port 29100 (Optional - only if firewall is running)
----------------------
**1.1.**  Run:

    sudo ufw allow 29100
    sudo ufw default allow outgoing
    sudo ufw enable

Step 2. ON LOCAL MACHINE: First run on your Local Wallet
----------------------

## If you are using the qt wallet:

**2.0.**  Open the wallet

**2.1.**  Click Help -> Debug window -> Console

**2.2.**  Generate xnodeprivkey:

    xnode genkey

(Store this key)

**2.3.**  Get wallet address:

    getaccountaddress XN1

**2.4.**  Send to received address **exactly 2000 HXX** in **1 transaction**. Wait for 15 confirmations.

**2.5.**  Close the wallet

## If you are using the daemon:

**2.0.**  Go to the checked out folder or where you extracted the binaries

    cd hexxcoin/src

**2.1.**  Start daemon:

    ./hexxcoind -daemon -server

**2.2.**  Generate xnodeprivkey:

    ./hexxcoin-cli xnode genkey

(Store this key)

**2.3.**  Get wallet address:

    ./hexxcoin-cli getaccountaddress XN1

**2.4.**  Send to received address **exactly 2000 HXX** in **1 transaction**. Wait for 15 confirmations.

**2.5.**  Stop daemon:

    ./hexxcoin-cli stop

## For both:

**2.6.**  Create file **xnode.conf** (in **~/.hexxcoin**, **C:\Users\USER\AppData\Roaming\hexxcoin** or **~/Library/Application Support/hexxcoin** depending on your Operating System) containing the following info:
 - LABEL: A one word name you make up to call your node (ex. XN1)
 - IP:PORT: Your xnode VPS's IP, and the port is always 29100.
 - XNODEPRIVKEY: This is the result of your "xnode genkey" from earlier.
 - TRANSACTION HASH: The collateral tx. hash from the 2000 HXX deposit.
 - INDEX: The Index from the transaction hash

To get TRANSACTION HASH, run:

```
./hexxcoin-cli xnode outputs
```
or
```
xnode outputs
```

depending on your wallet/daemon setup.

The output will look like:

    { "d6fd38868bb8f9958e34d5155437d009b72dfd33fc28874c87fd42e51c0f74fdb" : "0", }

Sample of xnode.conf:

    XN1 51.52.53.54:29100 XrxSr3fXpX3dZcU7CoiFuFWqeHYw83r28btCFfIHqf6zkMp1PZ4 d6fd38868bb8f9958e34d5155437d009b72dfd33fc28874c87fd42e51c0f74fdb 0

**2.7.** Lock unspent

It is a good idea to lock the unspent 2000 HXX you just transfered so you dont accidentially use them in an other transaction.

To do so enable coin control in the wallets settings and lock the 2000 HXX in the `Send` tab in `Inputs` like so:

![lockunspent](/lockunspent.png)

Step 3. ON VPS: Update config files
----------------------
**3.1.**  Create file **hexxcoin.conf** (in folder **~/.hexxcoin**)

    rpcuser=username
    rpcpassword=password
    rpcallowip=127.0.0.1
    server=1
    maxconnections=24
    xnode=1
    xnodeprivkey=XXXXXXXXXXXXXXXXX  ## Replace with your xnode private key
    externalip=XXX.XXX.XXX.XXX ## Replace with your node external IP


Step 4. ON LOCAL MACHINE: Start the xnode
----------------------
**4.1.**  Start xnode:

    ./hexxcoin-cli xnode start-alias <LABEL>

For example:

    ./hexxcoin-cli xnode start-alias XN1

**4.2.**  To check node status:

    ./hexxcoin-cli xnode debug

**Note:** on qt wallets you just ommit `./hexxcoin-cli` like before and use the debug console or use the `Xnodes` tab to start the xnode.

If not successfully started, just repeat start command
