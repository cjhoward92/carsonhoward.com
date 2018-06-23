const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const CopyPlugin = require('copy-webpack-plugin');

const outputDir = path.join(__dirname, "build/");

const isProd = process.env.NODE_ENV === 'production';

const plugins = [
  new HtmlWebpackPlugin({
    template: './src/index.html',
    filename: './index.html'
  }),
  new CopyPlugin(
    ['./src/styles.css'],
    {
      from: 'src',
      to: 'build'
    }
  )
];

const config = {
  entry: './src/Index.bs.js',
  mode: isProd ? 'production' : 'development',
  devtool: isProd ? '(none)' : 'source-map',
  output: {
    path: outputDir,
    filename: './Index.js',
  },
  plugins,
};

const devServer = {
  contentBase: outputDir
};

module.exports = isProd ? config : { ...config, devServer }
