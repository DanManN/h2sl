result=${PWD##*/}
if [ $result == "build" ]
then
  ./bin/h2sl-region-demo --input ../data/scripts/validation/symbols_test.xml --output /tmp/region_demo_out.xml
else
  echo "RUN THIS SCRIPT FROM ~/.../h2sl/build/"
fi
