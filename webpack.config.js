const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const CopyPlugin = require('copy-webpack-plugin');
const UglifyJS = require('uglifyjs-webpack-plugin');

const outputDir = path.join(__dirname, "build/");

const isProd = process.env.NODE_ENV === 'production';

const plugins = [
  new HtmlWebpackPlugin({
    template: './src/index.html',
    filename: './index.html'
  }),
  new CopyPlugin(
    [
      './src/styles.css',
      './src/resume.pdf',
      './src/Shaka_me.jpg'
    ],
    {
      from: 'src',
      to: 'build'
    }
  )
];

if (isProd) {
  plugins.push(new UglifyJS({
    test: /\.js($|\?)/i
  }));
}

const config = {
  entry: './src/Index.bs.js',
  mode: isProd ? 'production' : 'development',
  devtool: isProd ? '(none)' : 'source-map',
  output: {
    path: outputDir,
    filename: './Index.js',
  },
  module: {
    rules: [
      {
        test: /\.(png|svg|jpg|gif)$/,
        use: 'file-loader'
      }
    ]
  },
  plugins,
};

const devServer = {
  contentBase: outputDir
};

module.exports = isProd ? config : { ...config, devServer }
