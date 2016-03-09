#!/bin/sh
# Updates API documentation for gh-pages branch

mkdir ../gh-pages
cp -r Flurry\ API\ Documentation/* ../gh-pages/
cd ../gh-pages

git init
git config user.name travis
git config user.email travis@travis-ci.org
git remote add origin https://${GH_TOKEN}@github.com/flurry/flurry-ios-sdk.git > /dev/null
git checkout -b gh-pages
git add .
git commit -m "Updated API reference docs"

git push -fq origin gh-pages
