Alexey is stepping down from his role as the main packager and two new packagers have been appointed in his place:

- David Macek with signing key [0x9078f532](http://keys.gnupg.net/pks/lookup?search=0x87771331B3F1FF5263856A6D974C8BE49078F532&fingerprint=on&op=vindex)
- Christoph Reiter with signing key [0xa0aa7f57](http://keys.gnupg.net/pks/lookup?search=0x5F944B027F7FE2091985AA2EFA11531AA0AA7F57&fingerprint=on&op=vindex)

You can see the keys in full without relying on keyservers in the msys2-keyring GitHub repository.

We have released a new msys2-keyring package from that source (and a new installer that includes them) and we are waiting for a bit before uploading new databases and packages to give people time to update. If you don't update the keyring in time, you'll see something like this:

```
:: Synchronizing package databases...
downloading mingw32.db...
downloading mingw32.db.sig...
error: mingw32: key "4A6129F4E4B84AE46ED7F635628F528CF3053E04" is unknown
:: Import PGP key 4096R/87771331B3F1FF5263856A6D974C8BE49078F532, "David Macek <david.macek.0@gmail.com>", created: 2018-01-14? [Y/n]
error: mingw32: signature from "David Macek <david.macek.0@gmail.com>" is marginal trust
error: failed to update mingw32 (invalid or corrupted database (PGP signature))

downloading mingw64.db...
downloading mingw64.db.sig...
error: mingw64: signature from "David Macek <david.macek.0@gmail.com>" is marginal trust
error: failed to update mingw64 (invalid or corrupted database (PGP signature))

downloading msys.db...
downloading msys.db.sig...
error: msys: signature from "David Macek <david.macek.0@gmail.com>" is marginal trust
error: failed to update msys (invalid or corrupted database (PGP signature))
error: failed to synchronize all databases

error: mingw32: signature from "David Macek <david.macek.0@gmail.com>" is marginal trust
error: mingw64: signature from "David Macek <david.macek.0@gmail.com>" is marginal trust
error: msys: signature from "David Macek <david.macek.0@gmail.com>" is marginal trust
```

We have prepared the following steps to verify and install the new keyring manually after which you should be able to use pacman -Syu again:

```
$ curl -O https://repo.msys2.org/msys/x86_64/msys2-keyring-r21.b39fb11-1-any.pkg.tar.xz
$ curl -O https://repo.msys2.org/msys/x86_64/msys2-keyring-r21.b39fb11-1-any.pkg.tar.xz.sig

$ pacman-key --verify msys2-keyring-r21.b39fb11-1-any.pkg.tar.xz.sig
==> Checking msys2-keyring-r21.b39fb11-1-any.pkg.tar.xz.sig... (detached)
gpg: Signature made Mon Jun 29 07:36:14 2020 CEST
gpg:                using DSA key AD351C50AE085775EB59333B5F92EFC1A47D45A1
gpg: Good signature from "Alexey Pavlov (Alexpux) <alexpux@gmail.com>" [full]

# pacman -U msys2-keyring-r21.b39fb11-1-any.pkg.tar.xz
```

If you can't even import the key and the above command fails like this:

```
error: msys: key "4A6129F4E4B84AE46ED7F635628F528CF3053E04" is unknown
:: Import PGP key 4A6129F4E4B84AE46ED7F635628F528CF3053E04? [Y/n]
[...]
error: database 'msys' is not valid (invalid or corrupted database (PGP signature))
loading packages...
error: failed to prepare transaction (invalid or corrupted database)
```

... you have to convince pacman to not care about those databases for a while, for example like this:

```
# pacman -U --config <(echo) msys2-keyring-r21.b39fb11-1-any.pkg.tar.xz
```

If you still see signature errors, resetting your pacman key store might help:

```
# rm -r /etc/pacman.d/gnupg/
# pacman-key --init
# pacman-key --populate msys2
```