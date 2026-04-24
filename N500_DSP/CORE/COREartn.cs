using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Buchi.Core
{
    /// <summary>
    /// class holding an article number
    /// </summary>
    [Serializable()]
    public class CCOArticleInfo
    {
        /// <summary>
        /// article info
        /// </summary>
        private string m_sArticleInfo;

        /// <summary>
        /// construction
        /// </summary>
        /// <param name="p_sVersion">article number"</param>
        public CCOArticleInfo(string p_sArticleNo)
        {
            string l_sDummy = p_sArticleNo.Trim();
            m_sArticleInfo = l_sDummy.TrimStart(new Char[] { '0' });
        }

        /// <summary>
        /// transforms the article number into a string again!
        /// </summary>
        public string ArticleNo
        {
            get
            {
                return m_sArticleInfo;
            }
        }

        /// <summary>
        /// comparison operator
        /// </summary>
        /// <param name="p_Left"></param>
        /// <param name="p_Right"></param>
        /// <returns></returns>
        public static bool operator ==(CCOArticleInfo p_Left, CCOArticleInfo p_Right)
        {
            if (ReferenceEquals(p_Left, p_Right))
            {
                return true;
            }
            else if (ReferenceEquals(p_Left, null) || ReferenceEquals(p_Right, null))
            {
                return false;
            }

            string l_sLeft = p_Left.ArticleNo;
            string l_sRight = p_Right.ArticleNo;

            // compare string
            if (l_sLeft != l_sRight)
                return false;

            // seems to be identical
            return true;
        }

        /// <summary>
        /// comparison operator
        /// </summary>
        /// <param name="p_Left"></param>
        /// <param name="p_Right"></param>
        /// <returns></returns>
        public static bool operator !=(CCOArticleInfo p_Left, CCOArticleInfo p_Right)
        {
            return !(p_Left == p_Right);
        }

        /// <summary>
        /// checks, whether two object are the same
        /// </summary>
        /// <param name="p_Right"></param>
        /// <returns></returns>
        public override bool Equals(object p_Right)
        {
            return this == (CCOArticleInfo)p_Right;
        }

        /// <summary>
        /// supplies a hashcode
        /// </summary>
        /// <returns></returns>
        public override int GetHashCode()
        {
            // not usable!!
            return 0;
        }

        /// <summary>
        /// Returns a <see cref="T:System.String"/> that represents the current <see cref="T:System.Object"/>.
        /// </summary>
        /// <returns>
        /// A <see cref="T:System.String"/> that represents the current <see cref="T:System.Object"/>.
        /// </returns>
        public override string ToString()
        {
            return m_sArticleInfo;
        }
    }
}
