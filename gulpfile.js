const { watch, src, dest } = require('gulp');
const htmlmin = require('gulp-htmlmin');
const replace = require('gulp-replace');
const rename = require('gulp-rename');

function htmlMin() {
  return src('web/index.html')
    .pipe(htmlmin({
      collapseWhitespace: true,
      minifyJS: true,
    }))
    .pipe(rename((path) => {
      path.extname = ".min.html";
    }))
    .pipe(dest('dist'))
    .pipe(rename(path => {
      path.extname = ".h";
    }))
    .pipe(replace('"', '\\\"')) // escape double quotes
    .pipe(replace('\r\n', ''))  // remove all newlines (Win)
    .pipe(replace('\n', ''))    // remove all newlines (Linux)
    .pipe(replace(/^/, `"`))    // surround with quotes
    .pipe(replace(/$/, '\"'))
    .pipe(replace(/^/, '#define INDEX_HTML ')) // prepend #define
    .pipe(dest('dist'))
    .pipe(dest('src/web'));
}

exports.default = () => {
  htmlMin();
  watch('web/index.html', htmlMin);
};